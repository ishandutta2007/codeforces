#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
multiset<ll> st;
ll a[maxn] , res , s , n;
bool check(ll x)
{
    st.clear();
    res = 0;
    for(int i = 0; i < n; i++)
        st.insert((i + 1) * x + a[i]);
    while(x--)
        res += *st.begin() , st.erase(st.begin());
    return res <= s;
}
ll bs(ll l , ll r)
{
    if(r - l == 1)
    {
        if(check(r))
            return r;
        return l;
    }
    ll mid = (l + r) / 2;
    if(check(mid))
        return bs(mid , r);
    return bs(l , mid);
}
int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll k = bs(0 , n);
    check(k);
    cout << k << " " << res << endl;
}