#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll ans , a[maxn] , b[maxn];
set<pair<ll , ll> > st;
int main()
{
    ll n , f;
    cin >> n >> f;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        st.insert({min(2 * a[i] , b[i]) - min(a[i] , b[i]) , i});
        ans += min(a[i] , b[i]);
    }
    while(f--)
    {
        ans += st.rbegin() -> first;
        st.erase(*st.rbegin());
    }
    cout << ans;
}