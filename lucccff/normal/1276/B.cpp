#include <bits/stdc++.h>
using namespace std;

long long a[200010],b[200010],c[200010];
vector <int> e[200010];

void dfs(int k) {
    for(int i=0;i<b[k];i++) {
        if (a[e[k][i]]==0) {
            a[e[k][i]]=1;
            dfs(e[k][i]);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,x,y,r,ansx,ansy;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m>>x>>y;
        for(j=1;j<=n;j++) {
            a[j]=0;
            b[j]=0;
            c[j]=0;
        }
        for(j=0;j<m;j++) {
            cin>>l>>r;
            e[l].push_back(r);
            e[r].push_back(l);
            b[r]++;
            b[l]++;
        }
        a[x]=a[y]=10;
        ansx=ansy=0;
        dfs(x);
        for(j=1;j<=n;j++) {
            if (a[j]==1) {
                c[j]++;
            }
            a[j]=0;
        }
        a[x]=a[y]=10;
        dfs(y);
        for(j=1;j<=n;j++) {
            if (a[j]==1) {
                if (c[j]!=1) {
                    ansy++;
                }
            }
            else if (c[j]==1) {
                ansx++;
            }
            a[j]=0;
            e[j].clear();
        }
        cout<<ansx*ansy<<endl;
    }
    return 0;
}