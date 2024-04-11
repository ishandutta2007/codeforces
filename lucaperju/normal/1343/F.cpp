#include <bits/stdc++.h>
using namespace std;
int permc[203],n;
int fvc[203];
int fol[203];
vector<int>v[203];
int search (int pz)
{
    for(int i=1;i<=n-1;++i)
    {
        if(fol[i])
            continue;
        int j;
        for(j=1;j<=n;++j)
            fvc[j]=0;
        for(j=0;j<v[i].size();++j)
            ++fvc[v[i][j]];
        for(j=1;j<pz;++j)
            --fvc[permc[j]];
        for(j=2;j<pz;++j)
            if(fvc[permc[j]]==-1 && fvc[permc[j-1]]==0)
                return -1;
        int cnt=0;
        for(j=1;j<=n;++j)
            if(fvc[j]==1)
                ++cnt;
        if(cnt==1)
        {
            for(j=1;j<=n;++j)
                if(fvc[j]==1)
                {
                    fol[i]=1;
                    return j;
                }
        }
    }
    return -1;
}
bool verif (int val)
{
    permc[1]=val;
    for(int i=1;i<n;++i)
        fol[i]=0;
    for(int i=2;i<=n;++i)
    {
        val=search(i);
        if(val==-1)
            return false;
        permc[i]=val;
    }
    for(int i=1;i<=n;++i)
        cout<<permc[i]<<' ';
    cout<<'\n';
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,m,i,j=0,t,x,z,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<n;++i)
            v[i].clear();
        for(i=1;i<n;++i)
        {
            int a;
            cin>>a;
            for(j=1;j<=a;++j)
            {
                int b;
                cin>>b;
                v[i].push_back(b);
            }
        }
        for(i=1;i<=n;++i)
            if(verif(i))
                break;
    }
    return 0;
}