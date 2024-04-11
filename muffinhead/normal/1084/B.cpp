#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n; ll vol; cin >> vol;
    vl data; F0R(i, n) {
        ll cur; cin >> cur;
        data.pb(cur);
    }
    sort(all(data));
    ll sum = 0;
    F0R(i, n) {
        sum += data[i];
    }
    if (sum < vol) {
        cout << -1 << endl; return 0;
    }
    if (sum - data[0] * n >= vol) {
        cout << data[0] << endl; return 0;
    }
    ll remaining = vol - sum + data[0] * n;
    ll perN = remaining / n;
    if (remaining % n != 0) perN++;
    cout << data[0] - perN << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343