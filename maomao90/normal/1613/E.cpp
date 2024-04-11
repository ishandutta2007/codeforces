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
#define MAXN 1000005

int dirr[] = {1, 0, -1, 0}, dirc[] = {0, 1, 0, -1};

int t;
int n, m;
char tmp[MAXN];
string grid[MAXN];
queue<ii> bfs;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n) {
			scanf(" %s", tmp);
			grid[i] = tmp;
		}
		REP (i, 0, n) {
			REP (j, 0, m) {
				if (grid[i][j] == 'L') {
					REP (k, 0, 4) {
						int vr = i + dirr[k], vc = j + dirc[k];
						if (vr >= n || vr < 0 || vc >= m || vc < 0) continue;
						if (grid[vr][vc] == '.') {
							bfs.push(MP(vr, vc));
						}
					}
				}
			}
		}
		while (!bfs.empty()) {
			auto [ur, uc] = bfs.front(); bfs.pop();
			int cnt = 0;
			REP (i, 0, 4) {
				int vr = ur + dirr[i], vc = uc + dirc[i];
				if (vr >= n || vr < 0 || vc >= m || vc < 0) continue;
				cnt += grid[vr][vc] == '.';
			}
			if (cnt <= 1) {
				grid[ur][uc] = '+';
				REP (i, 0, 4) {
					int vr = ur + dirr[i], vc = uc + dirc[i];
					if (vr >= n || vr < 0 || vc >= m || vc < 0) continue;
					if (grid[vr][vc] == '.') {
						bfs.push(MP(vr, vc));
					}
				}
			}
		}
		REP (i, 0, n) {
			printf("%s\n", grid[i].c_str());
		}
	}
	return 0;
}