#include <bits/stdc++.h>

using namespace std;
vector<int>v[600005];
int dep[600005],viz[600005];
vector<vector<int> > rz;
vector<int>vc;
void dfs (int pz)
{
    viz[pz]=1;
    int ok=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            vc.push_back(v[pz][i]);
            dep[v[pz][i]]=1+dep[pz];
            dfs(v[pz][i]);
            vc.push_back(pz);
        }
        else
        {
            if(dep[v[pz][i]]>dep[pz])
                continue;
            if(dep[v[pz][i]]!=dep[pz]-1 || ok)
            {
                vc.push_back(v[pz][i]);
                vc.push_back(pz);
            }
            else
                ok=1;
        }
    }
}
int mat[3][300005];
char m1[3][300005],m2[3][300005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int s=k;
        int mx=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            mx=max(mx,(s|a));
        }
        cout<<mx<<'\n';
    }
    return 0;
}