
/**
    Chtholly Nota Seniorious
**/
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int T;
 
void solve()
{
    int n,i,maxi;
    unordered_map<int,int> mp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int r, A = a;
        int mul = 1;
        for(r=2;r<=sqrt(A);r++)
        {
            int counti = 0;
            while(a%r == 0)
                counti++,a/=r;
            if(counti%2 == 1)
                mul *= r;
        }
        if(a != 1)
            mul *= a;
        mp[mul]++;
    }
    int ans1 = 0,ans2 = 0,ans3 = 0;
    for(auto it: mp)
    {
        ans1 = max(ans1,it.second);
        if(it.second%2 == 0)
            ans2 += it.second;
    }
    if(mp[1]%2 == 1)
        ans2 += mp[1];
    long long q;
    cin>>q;
    while(q--)
    {
        long long m;
        cin>>m;
        if(m == 0)
            cout<<ans1<<"\n";
        else
            cout<<max(ans2,ans1)<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>T;
    while(T--)
        solve();
    return 0;
}