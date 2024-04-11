#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int cnt[200005],ok[200005],k;
void dfs (int pz,int t)
{
    int cntc=0;
    int okk=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        int nn=v[pz][i];
        dfs(nn,pz);
        cnt[pz]+=cnt[nn];
        if(ok[nn])
            ++cntc;
        else
            okk=0;
    }
    if(cntc%k==0 && okk)
        ok[pz]=1;
    cnt[pz]+=cntc/k;
}
int main()
{
    long long n,m,i,j,x,y,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            ok[i]=cnt[i]=0;
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=n;++i)
        {
            int a=v[i].size();
            --a;
            if(a%k)
                break;
        }
        if(i==n+1)
        {
            if(n/k*k<n)
                cout<<n/k<<'\n';
            else
                cout<<n/k-1<<'\n';
            continue;
        }
        dfs(i,-1);
        cout<<cnt[i]<<'\n';
    }
    return 0;
}