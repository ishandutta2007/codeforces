#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#include <iomanip>
#include <random>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

const int MAXN = 1e5 + 13;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
int par[MAXN];
int cc;

void init() {
	for (int i = 0; i < N; i++) {
		par[i] = i;
	}
}
int find(int u) {
	if (u == par[u]) {
		return u;
	}
	par[u] = find(par[u]);
	return par[u];
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return false;
	}
	par[u] = v;
	return true;
}


int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	init();
	cc = N;
	FOR(i, 0, M)
	{
		int u, v;
		cin >> u >> v; u--; v--;
		if (merge(u, v))
		{
			cc--;
		}
	}
	cout << M - (N - cc) << '\n';
    return 0;
}