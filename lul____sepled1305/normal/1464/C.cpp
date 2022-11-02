/**
    Ithea Myse Valgulious
**/
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
 
ll power(ll base, ll pow)
{
    ll cur = 1;
    while(pow--)
        cur*=base;
    return cur;
}
 
void solve()
{
    ll n, t, i;
    cin>>n>>t;
    string s;
    cin>>s;
    vector<int> v;
    for(i=0;i<n;i++)
        v.push_back(s[i]-'a');
    t -= power(2,v.back());
    v.pop_back();
    t += power(2,v.back());
    v.pop_back();
    sort(v.begin(),v.end());
    while(!v.empty())
    {
        if(t < 0)
            t = -t;
        ll cur = power(2,v.back());
        v.pop_back();
        t-=cur;
    }
    if(t==0)
        cout<<"Yes";
    else
        cout<<"No";
}
 
int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/
 
    solve();
    return 0;
}