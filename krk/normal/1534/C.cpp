#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int T;
int n;
vector <int> my[Maxn];
int par[Maxn], siz[Maxn];
int comp;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	comp--;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			my[i].clear();
			par[i] = i; siz[i] = 1;
		}
		comp = n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++) {
				int a; scanf("%d", &a);
				my[a].push_back(j);
			}
		for (int i = 1; i <= n; i++)
			unionSet(my[i][0], my[i][1]);
		int res = 1;
		while (comp--)
			res = 2ll * ll(res) % mod;
		printf("%d\n", res);
	}
    return 0;
}