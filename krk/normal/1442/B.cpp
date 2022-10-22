#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];
int b[Maxn];
int L[Maxn], R[Maxn];
int lst[Maxn];
bool rem[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		fill(lst, lst + n + 1, -1);
		fill(rem, rem + n + 1, false);
		for (int i = 0; i < k; i++) {
			scanf("%d", &b[i]);
			lst[b[i]] = i;
		}
		R[0] = a[0];
		L[n + 1] = a[n - 1];
		for (int i = 0; i < n; i++) {
			if (i - 1 >= 0) L[a[i]] = a[i - 1];
			else L[a[i]] = 0;
			if (i + 1 < n) R[a[i]] = a[i + 1];
			else R[a[i]] = n + 1; 
		}
		int res = 1;
		for (int i = 0; i < k && res != 0; i++) {
			if (rem[b[i]]) { res = 0; break; }
			vector <int> seq;
			if (L[b[i]] > 0 && lst[L[b[i]]] <= i)
				seq.push_back(L[b[i]]);
			if (R[b[i]] <= n && lst[R[b[i]]] <= i)
				seq.push_back(R[b[i]]);
			if (seq.empty()) { res = 0; break; }
			if (seq.size() == 2) res = 2ll * res % mod;
			int ind = seq[0];
			rem[ind] = true;
			R[L[ind]] = R[ind];
			L[R[ind]] = L[ind];
		}
		printf("%d\n", res);

	}
    return 0;
}