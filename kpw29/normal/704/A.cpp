#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, k, a, b, c;
#define maxn 300010
vector <int> v[maxn];
int last[maxn], type, x;
const int R = (1 << 19);
int dr[2 * R + 5], czas;

bool read[maxn];
int main() {
	int notifs = 0, czas = 0, unread = 0, WSK = 1;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)  last[i] = -1;
	while (m--) {
		scanf("%d", &type);
		if (type == 1) {
			++notifs;
			scanf("%d", &a);
			v[a].pb(notifs);
			++unread;
		}
		if (type == 2) {
			scanf("%d", &a);
			int miejsce = last[a];
			for (int i=miejsce+1; i<(int)v[a].size(); ++i) {
				int u = v[a][i];
				if (!read[u]) --unread;
				read[u] = 1;
			}
			last[a] = v[a].size() - 1;
		}
		if (type == 3) {
			scanf("%d", &a);
			czas = max(a, czas);
			while (WSK <= czas) {
				if (!read[WSK]) unread--;
				read[WSK] = 1;
				++WSK;
			}
		}
		printf("%d\n", unread);
		
	}
}