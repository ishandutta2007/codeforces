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

int N;
vi data;
vector<vector<pair<int, ll> > > graph;

ll best = 0;

ll dp(int vertex, int parent) { //return best single-strand result
    vector<ll> paths;

    F0R(i, graph.at(vertex).size()) {
        int curVertex = graph.at(vertex).at(i).first;
        if (curVertex == parent) {
            continue;
        }
        ll value = dp(curVertex, vertex);
        if (value >= graph.at(vertex).at(i).s) {
            value -= graph.at(vertex).at(i).s;
            paths.pb(value);
        }
    }
    paths.pb(0);
    paths.pb(0);
    sort(all(paths));
    int curCount = paths.size();
    best = max(best, data[vertex] + paths[curCount - 1] + paths[curCount - 2]);
    return data[vertex] + paths[curCount - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    F0R(i, N) {
        int cur; cin >> cur; data.pb(cur);
        vector<pair<int, ll> > d; graph.pb(d);
    }

    F0R(i, N-1) {
        int a, b, c; cin >> a >> b >> c;
        graph[a-1].pb(mp(b-1, c));
        graph[b-1].pb(mp(a-1, c));

    }


    dp(0, -1);
    cout << best << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343