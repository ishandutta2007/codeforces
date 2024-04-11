#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005
#define MAXX 900000

int n, m, l;
char pat[MAXN][10], s[MAXN][10], ts[10];
int mt[MAXN];
vi imt[MAXN];
int id[MAXX];
int out[MAXN];
bool useful[MAXN];
bool pos;
queue<int> q;
vi ans;

int stoi(char* s) {
	int cur = 0;
	REP (i, 0, l) {
		cur *= 30;
		cur += (s[i] == '_' ? 0 :  s[i] - 'a' + 1);
	}
	return cur;
}

int main() {
	scanf("%d%d%d", &n, &m, &l);
	memset(id, -1, sizeof id);
	REP (i, 0, n) {
		scanf(" %s", pat[i]);
		id[stoi(pat[i])] = i;
	}
	pos = 1;
	REP (i, 0, m) {
		scanf(" %s", s[i]);
		scanf("%d", &mt[i]);
		mt[i]--;
		imt[mt[i]].pb(i);
		useful[mt[i]] = 1;
		bool found = 0;
		REP (j, 0, 1 << l) {
			REP (k, 0, l) {
				if (j & (1 << k)) {
					ts[k] = '_';
				} else {
					ts[k] = s[i][k];
				}
			}
			int tid = stoi(ts);
			if (id[tid] == -1) {
				continue;
			}
			found |= (id[tid] == mt[i]);
			out[id[tid]]++;
		}
		if (!found) pos = 0;
	}
	if (!pos) {
		printf("NO\n");
		return 0;
	}
	REP (i, 0, n) {
		if (!useful[i]) continue;
		debug("%d: %d\n", i, out[i]);
		if (out[i] == imt[i].size()) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ans.pb(u);
		for (int i : imt[u]) {
			REP (j, 0, 1 << l) {
				REP (k, 0, l) {
					if (j & (1 << k)) {
						ts[k] = '_';
					} else {
						ts[k] = s[i][k];
					}
				}
				int tid = stoi(ts);
				if (id[tid] == -1) {
					continue;
				}
				if (!useful[id[tid]]) continue;
				if (--out[id[tid]] == imt[id[tid]].size()) {
					q.push(id[tid]);
				}
			}
		}
	}
	REP (i, 0, n) {
		if (!useful[i]) {
			ans.pb(i);
		}
	}
	if (ans.size() != n) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i : ans) {
			printf("%d ", i + 1);
		}
		printf("\n");
	}
	return 0;
}