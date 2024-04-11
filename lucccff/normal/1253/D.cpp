#include <bits/stdc++.h>
using namespace std;

/*typedef struct node{
    int num,data;
}node;

bool cmp(node a,node b) {
    return a.data<b.data;
}
node e[100010];*/

int b[200010],c[200010],d[200010],x[200010];
vector <int> a[200010];
map <int,int> p;

void dfs(int i,int k) {
    int j;
    c[i]=k;
    for(j=0;j<b[i];j++) {
        if (d[a[i][j]]==0) {
            d[a[i][j]]=1;
            dfs(a[i][j],k);
        }
    }
}
int main(){
    int i,j,k,l,m,n,s;
    cin>>n>>m;
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(c,-1,sizeof(c));
    for(i=0;i<m;i++) {
        cin>>k>>l;
        b[k]++;
        b[l]++;
        a[k].push_back(l);
        a[l].push_back(k);
    }
    for(i=1;i<=n;i++) {
        if (c[i]==-1) {
            dfs(i,i);
        }
    }
    /*for(i=1;i<=n;i++) {
        e[i].data=c[i];
        e[i].num=i;
    }
    sort(e+1,e+1+n,cmp);
    e[0].data=0;
    for(i=1;i<=n;i++) {
        if (e[i].data!=e[i-1].data) {
            x[e[i].data]=i;
        }
    }*/
    s=0;
    for(i=n;i>=1;i--) {
        if (c[i]<i) {
            j=i;
            k=c[i];
            while(j>k) {
                j--;
                if (c[j]<k) k=c[j];
            }
            l=0;
            for(k=j;k<=i;k++) {
                if (p.count(c[k])==0) {
                    l++;
                    p[c[k]]=1;
                }
            }
            p.clear();
            s+=l-1;
            i=j;
        }
    }
    cout<<s;
    return 0;
}