#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int n, m, a, b, c, k;
ll N, M, A, B, C;
int pos[5];
int miejsce[maxn], pl[maxn];
int main() {
	scanf("%d%d", &n, &k);
	pos[0] = 0;
	pos[1] = 1;
	int type =0;
	for (int i=1; i<=k; ++i) {
		scanf("%d", &type);
		if (type == 2) {
			if (pos[0] & 1) pos[0]--;
			else pos[0]++;
			if (pos[1] & 1) pos[1]--;
			else pos[1]++;
		}
		else {
			scanf("%d", &a);
			pos[0] = (pos[0] + a + n)%n;
			pos[1] = (pos[1] + a + n)%n;
		}
	}
	
	miejsce[1] = pos[0] + 1;
	miejsce[2] = pos[1] + 1;
	pos[1]--;

	for (int i=3; i<=n; ++i) {
		int ile = pos[(i % 2) ^ 1];
		miejsce[i] = (i + pos[(i % 2) ^ 1] + n - 1) % n + 1;
	}

	for (int i=1; i<=n; ++i) pl[miejsce[i]] = i;
	for (int i=1; i<=n; ++i) printf("%d ", pl[i]);
	
}