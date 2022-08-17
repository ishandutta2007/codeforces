// Example program
#include <bits/stdc++.h>
#include <map>

using namespace std;

typedef long long ll;
map<ll, ll> m;

vector<ll> st2;

ll m1[100005];

int main()
{
    int n;
    ll a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>m1[i];
        m[m1[i]]++;
    }
    ll cur = 1;
    for(int i = 0; i < 35; i++)
    {
        cur*=2;
        st2.push_back(cur);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll c1 = m1[i];
        for (int j = 0; j < st2.size(); j++) 
        {
            ll c2 = st2[j] - c1;
            ans += m[c2];
            if (c2 == c1) ans--;
        }
    }
    cout << ans / 2;
}