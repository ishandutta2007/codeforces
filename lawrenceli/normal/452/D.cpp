#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

int k, n[3], t[3], m[3], num, cur;
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> k;
    rep(i, 3) cin >> n[i];
    rep(i, 3) cin >> t[i];
    m[0] = k;
    while (num < k) {
        rep(i, 3)
            while (m[i] && n[i])
                m[i]--, n[i]--, pq.push(pii(cur+t[i], i));
        pii p = pq.top(); pq.pop();
        cur = p.fi;
        n[p.se]++;
        if (p.se == 2) num++;
        else m[p.se+1]++;
    }

    cout << cur << '\n';
    return 0;
}