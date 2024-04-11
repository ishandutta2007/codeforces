#include <bits/stdc++.h>
using namespace std;

vector <pair <int,int>> e[200010];
long long b[200010],in[200010],p[200010],ans,n;

int dfs1(int j,int k) {
    int l;
    in[j]=k;
    k++;
    for(int i=0;i<b[j];i++) {
        if (in[e[j][i].first]==0) {
            l=dfs1(e[j][i].first,k);
            if ((l-k)%2!=0) {
                ans+=p[e[j][i].second];
            }
            k=l;
        }
    }
    return k;
}

int dfs2(int j,int k) {
    int l;
    in[j]=k;
    k++;
    for(int i=0;i<b[j];i++) {
        if (in[e[j][i].first]==0) {
            l=dfs2(e[j][i].first,k);
            if (l-k>n) {
                ans+=(2*n-(l-k))*p[e[j][i].second];
            }
            else {
                ans+=(l-k)*p[e[j][i].second];
            }
            k=l;
        }
    }
    return k;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=1;j<=2*n;j++) b[j]=0;
        for(j=0;j<2*n-1;j++) {
            cin>>k>>l>>m;
            e[k].push_back(make_pair(l,j));
            e[l].push_back(make_pair(k,j));
            b[k]++;
            b[l]++;
            p[j]=m;
        }
        for(j=1;j<=2*n;j++) {
            in[j]=0;
        }
        ans=0;
        dfs1(1,1);
        cout<<ans<<' ';
        for(j=1;j<=2*n;j++) {
            in[j]=0;
        }
        ans=0;
        dfs2(1,1);
        cout<<ans<<endl;
        for(j=1;j<=2*n;j++) {
            e[j].clear();
        }
    }
    return 0;
}