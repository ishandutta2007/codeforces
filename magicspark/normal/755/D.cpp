#include<bits/stdc++.h>
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

struct segtree
{
    vi vals;
    int tsz;

    segtree (int n)
    {
        tsz = 1;
        while (tsz <= n)
            tsz *= 2;
        vals.assign(2 * tsz, 0);
    }

    void put (int pos, int what)
    {
        vals[pos += tsz] = what;
        for (pos >>= 1; pos > 0; pos >>= 1)
            vals[pos] = vals[2 * pos] + vals[2 * pos + 1];
    }

    int getsum (int l, int r)
    {
        int ans = 0;
        for (l += tsz, r += tsz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans += vals[l++];
            if (r & 1)
                ans += vals[--r];
        }
        return ans;
    }
};

void solve (int n)
{
    int k;
    cin >> k;
    if (2 * k >= n)
        k = n - k;

    segtree data(3 * n);
    int x = 0;

    ll cur = 1;
    for (int i = 0; i < n; i++)
    {
        int l = n + x - k + 1, r = n + x + k;
        cur += data.getsum(l, r) + 1;
        data.put(x, 1);	
        data.put(x + n, 1);
        data.put(x + (n << 1), 1);
        x = r % n;
        cout << cur << ' ';
    }
    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
        solve(n);
}