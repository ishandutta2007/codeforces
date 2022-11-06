#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;

ll qpow(int x, ll k)
{
    if (!k) return 1;
    if (k == 1) return x;
    ll t = qpow(x, k >> 1);
    return min(t * t * qpow(x, k & 1), (ll)(1e9));
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll t = qpow(2, n);
    cout << m % t << endl;
    return 0;
}