#include <bits/stdc++.h>

using namespace std;
int fv[100003];
vector<int>v[100003];
int rz[100003];
int ord[100003];
bool cmp (int a, int b)
{
    return v[a].size()<v[b].size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
            fv[i]=0;
        for(i=1;i<=m;++i)
            v[i].clear();
        int lim=(m+1)/2;
        for(i=1;i<=m;++i)
        {
            int a;
            cin>>a;
            for(j=1;j<=a;++j)
            {
                int b;
                cin>>b;
                v[i].push_back(b);
            }
            sort(v[i].begin(),v[i].end());
            ord[i]=i;
        }
        sort(ord+1,ord+m+1,cmp);
        for(i=1;i<=m;++i)
        {
            int pz=ord[i];
            for(j=0;j<v[pz].size();++j)
            {
                if(fv[v[pz][j]]<lim)
                {
                    rz[pz]=v[pz][j];
                    ++fv[v[pz][j]];
                    break;
                }
            }
            if(j==v[pz].size())
                break;
        }
        if(i<=m)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i=1;i<=m;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}