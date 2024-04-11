#include <bits/stdc++.h>
using namespace std;
bool ok[200005];
int vv[200005];
vector <int> v[200005];
int rz[200005];
bool cmp (int a, int b)
{
    return v[a].size()>v[b].size();
}
int main ()
{
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        k=0;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=n;++i)
            ok[i]=0,vv[i]=i;
        sort(vv+1,vv+n+1,cmp);
        for(i=1;i<=n;++i)
        {
            if(!ok[vv[i]])
            {
                int x=i;
                i=vv[i];
                rz[++k]=i;
                for(j=0;j<v[i].size();++j)
                    ok[v[i][j]]=1;
                i=x;
            }
        }
        if(k<=n/2)
        {
        cout<<k<<'\n';
        for(i=1;i<=k;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
        }
        else
        {
            cout<<n-k<<'\n';
            for(i=1;i<=n;++i)
                ok[i]=0;
            for(i=1;i<=k;++i)
                ok[rz[i]]=1;
            for(i=1;i<=n;++i)
                if(!ok[i])
                    cout<<i<<' ';
            cout<<'\n';
        }
    }
    return 0;
}