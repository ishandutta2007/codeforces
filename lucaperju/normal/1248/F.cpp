#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
vector <int> v[1000005];
vector <int> rev[1000005];
vector <int> vvv[1000005];
int rez[1000005];
int viz[1000005],k;
void dfs (int poz) {
    viz[poz]=1;
    int i,nn;
    for(i=0; i<v[poz].size(); ++i) {
        nn=v[poz][i];
        if(!viz[nn])
            dfs(nn);
    }
    rez[++k]=poz;
}
void cazanelu (int poz)
{
    int i,nn;
    viz[poz]=2;
    vvv[k].push_back(poz);
    for(i=0;i<rev[poz].size();++i)
    {
        nn=rev[poz][i];
        if(viz[nn]!=2)
            cazanelu(nn);
    }
}
int main() {
    int n,m,i,j,t;
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i=1; i<=n; ++i) {
            v[i].clear();
            rev[i].clear();
            viz[i]=0;
            vvv[i].clear();
            rez[i]=0;
        }
        for(i=1; i<=m; ++i) {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            rev[b].push_back(a);
        }
        k=0;
        for(i=1; i<=n; ++i) {
            if(!viz[i])
                dfs(i);
        }
        k=0;
        for(i=n; i>=1; --i) {
            int delimanu=rez[i];
            if(viz[delimanu]==2)
                continue;
            ++k;
            cazanelu(delimanu);
        }
        if(k==1)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
            cout<<vvv[k].size()<<' '<<(n-vvv[k].size())<<'\n';
            for(i=0;i<vvv[k].size();++i)
            {
                cout<<vvv[k][i]<<' ';
                viz[vvv[k][i]]=69;
            }
            cout<<'\n';
            for(i=1;i<=n;++i)
                if(viz[i]!=69)
                    cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}