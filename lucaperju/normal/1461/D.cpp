#include <bits/stdc++.h>

using namespace std;
int v[100003];
long long sp[100003];
map<long long,bool>mp;
void compute (int st, int dr, int fel)
{
    long long sc=sp[dr]-sp[st-1];
    if(fel==1)
        mp[sc]=true;
    else
        mp[sc]=false;
    if(v[st]==v[dr])
        return;
    int mid=(v[st]+v[dr])/2;
    int i;
    for(i=st;v[i]<=mid;++i);
    --i;
    compute(st,i,fel);
    compute(i+1,dr,fel);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long j,i,k;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        sort(v+1,v+n+1);
        for(i=1;i<=n;++i)
            sp[i]=v[i]+sp[i-1];
        compute(1,n,1);
        for(i=1;i<=m;++i)
        {
            int a;
            cin>>a;
            if(mp[a])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        compute(1,n,0);
    }
    return 0;
}