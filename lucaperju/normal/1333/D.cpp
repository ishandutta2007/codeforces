#include <bits/stdc++.h>

using namespace std;
int v[3003],n;
vector<int> solmn[3000003];
int ok[3003];
bool check ()
{
    for(int i=1;i<n;++i)
        if(v[i]==1 && v[i+1]==2)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,rz=1,mx=0;
    int k;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        if(c=='R')
            v[i]=1;
        else
            v[i]=2;
    }
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]==1)
            ++cnt;
        else
            mx+=cnt;
    }
    if(k>mx)
    {
        cout<<-1;
        return 0;
    }
    int pz=0;
    while(!check())
    {
        ++pz;
        for(i=1;i<n;++i)
        {
            ok[i]=0;
            if(v[i]==1 && v[i+1]==2)
            {
                solmn[pz].push_back(i);
                ok[i]=1;
            }
        }
        for(i=1;i<n;++i)
            if(ok[i])
                swap(v[i],v[i+1]);
    }
    if(k<pz)
    {
        cout<<-1;
        return 0;
    }
    k-=pz;
    for(i=1;i<=pz;++i)
    {
        while(solmn[i].size()>1 && k)
        {
            cout<<1<<' '<<solmn[i].back()<<'\n';
            solmn[i].pop_back();
            --k;
        }
        cout<<solmn[i].size()<<' ';
        for(j=0;j<solmn[i].size();++j)
            cout<<solmn[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}