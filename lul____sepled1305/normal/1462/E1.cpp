#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
vector<ll> fac;

ll binom(ll a)
{
    if(a < 2)
        return 0;
    return ((a)*(a-1))/2;
}

void solve()
{
    int n,m=3,k=2,i;
    vector<int> v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int pointer1=0,pointer2=0;
    ll su = 0;
    for(pointer1=0;pointer1<n;pointer1++)
    {
        while(pointer2<n && v[pointer2]<=v[pointer1]+k)
            pointer2++;
        pointer2--;
        su += binom(pointer2-pointer1);
    }
    cout<<su<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}