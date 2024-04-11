#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
 
int GCD(int a,int b)
{
    if(a > b)
        swap(a,b);
    if(a == 0)
        return b;
    if(b%a == 0)
        return a;
    return GCD(b%a,a);
}
 
void solve()
{
    map<pii,int> mp;
    int n,i;
    long long ans = 0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x = c-a,y = d-b;
        int r = x, e =y;
        x = x/GCD(abs(r),abs(e));
        y = y/GCD(abs(r),abs(e));
        ans+=mp[{-x,-y}];
        mp[{x,y}]++;
    }
    cout<<ans<<endl;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}