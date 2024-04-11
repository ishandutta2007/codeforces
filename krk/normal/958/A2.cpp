#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 2005;
const int Maxm = 205;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 37;
const int arg2 = 1000007;

int n, m;
char A[Maxn][Maxm];
char B[Maxm][Maxn];
map <ii, int> M;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", A[i]);
	for (int i = 0; i + m <= n; i++) {
		ii h = ii(0, 0);
		for (int j = 0; j < m; j++)
			for (int l = 0; l < m; l++) {
				h.first = (ll(h.first) * arg1 + ll(A[i + j][l] - 'a' + 1)) % mod1;
				h.second = (ll(h.second) * arg2 + ll(A[i + j][l] - 'a' + 1)) % mod2;
			}
		M[h] = i;
	}
	for (int i = 0; i < m; i++)
		scanf("%s", B[i]);
	for (int j = 0; j + m <= n; j++) {
		ii h = ii(0, 0);
		for (int i = 0; i < m; i++)
			for (int l = 0; l < m; l++) {
				h.first = (ll(h.first) * arg1 + ll(B[i][j + l] - 'a' + 1)) % mod1;
				h.second = (ll(h.second) * arg2 + ll(B[i][j + l] - 'a' + 1)) % mod2;
			}
		map <ii, int>::iterator it = M.find(h);
		if (it != M.end()) { printf("%d %d\n", it->second + 1, j + 1); return 0; }
	}
	return 0;
}