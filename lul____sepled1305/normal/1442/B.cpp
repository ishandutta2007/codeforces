
#include<bits/stdc++.h>
using namespace std;
int T;
int mod = 998244353;
 
int mul(int a, int b)
{
    return (int) ((1LL*a*b)%mod);
}
 
void solve()
{
    int n,k,i;
    map<int,int> mp;
    cin>>n>>k;
    int tl[n+2];
    int a[n];
    for(i=0;i<n;i++)
    {
        tl[i+1] = 0;
        cin>>a[i+1];
        mp.insert({a[i+1],i+1});
    }
    tl[0] = 1e9;
    tl[n+1] = 1e9;
    for(i=0;i<k;i++)
    {
        int b;
        cin>>b;
        tl[mp[b]] = i+1;
    }
    int ans = 1;
    for(i=1;i<n+1;i++)
    {
        int turn;
        if(tl[i-1] > tl[i] && tl[i+1] > tl[i] && tl[i]!=0)
            turn = 0;
        else if(tl[i-1] < tl[i] && tl[i+1] < tl[i])
            turn = 2;
        else
            turn = 1;
        ans = mul(ans,turn);
    }
    cout<<ans<<endl;
}
 
int main()
{
    cin>>T;
    while(T--)
        solve();
    return 0;
}