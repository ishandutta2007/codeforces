// time-limit: 2000
// problem-url: https://codeforces.com/contest/1591/problem/D
// Be kind and compassionate to one another, forgiving each other,
// just as in Christ God forgave you. Ephesians 4:32
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
#define MAXN 500005

int n;
int a[MAXN], cnt[MAXN];
bool visited[MAXN];

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		REP (i, 0, n + 1) {
			cnt[i] = visited[i] = 0;
		}
		bool pos = 0;
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			if(cnt[a[i]]++ >= 1) {
				pos = 1;
			}
			a[i]--;
		}
		if (pos) {
			printf("YES\n");
			continue;
		}
		int ans = n;
		REP (i, 0, n) {
			if (visited[i]) continue;
			ans--;
			visited[i] = 1;
			int u = i;
			while (a[u] != i) {
				u = a[u];
				visited[u] = 1;
			}
		}
		if (ans % 2 == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}