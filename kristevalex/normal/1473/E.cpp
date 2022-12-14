#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
template<typename T>
using priority_queue_l = priority_queue<T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


long long a, b, k, n, m, tmp, ans = 0;

vector<long long> dists;
vector<vector<pair<int, long long>>> g;

const ll INF = 1e16;

void cl()
{
    for (int i = 0; i < dists.size(); ++i)
    {
        dists[i] = INF;
    }
    dists[0] = 0ll;
}

int deix() {
	priority_queue<pair<ll, int>> q;
	for (int i = 0; i < dists.size(); ++i)
        q.push({-dists[i], i});

	while (!q.empty()) {
		int v = q.top().second;
		long long cur_d = -q.top().first;
		q.pop();
		if (cur_d > dists[v])
            continue;

		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first;
			long long len = g[v][j].second;

			if (dists[v] + len < dists[to]) {
				dists[to] = dists[v] + len;
				q.push({-dists[to], to});
			}
		}
	}
}

void eds(int mlt)
{
    auto dists_copy = dists;
    for (int i = 0; i < dists.size(); ++i)
        dists[i] = INF;

    for (int cur = 0; cur < g.size(); ++cur)
    {
        for (int i = 0; i < g[cur].size(); ++i)
        {
            auto next = g[cur][i];
            dists[next.ft] = min(dists[next.ft], dists_copy[cur] + (1 + mlt) * next.sd);
        }
    }
}

void print()
{
    for (int i = 0; i < dists.size(); ++i)
    {
        cout << dists[i] << ' ';
    }
    cendl;
    cendl;
}

int solve()
{
    cin >> n >> m;
    dists.resize(n);
    g.resize(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    cl();
    //print();
    deix();
    //print();
    eds(-1);
    //print();
    deix();
    //print();
    eds(1);
    //print();
    deix();
    //print();

    auto ord1 = dists;

    cl();
    deix();
    eds(1);
    deix();
    eds(-1);
    deix();

    for (int i = 0; i < g[0].size(); ++i)
    {
        auto next = g[0][i];
        dists[next.ft] = min(dists[next.ft], next.sd);
    }


    for (int i = 1; i < dists.size(); ++i)
    {
        cout << min(dists[i], ord1[i]) << ' ';
    }

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}