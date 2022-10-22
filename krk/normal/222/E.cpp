#include <cstdio>
#include <cctype>
using namespace std;

typedef long long ll;

const int Maxm = 52;
const int mod = 1000000007;

ll n;
int m, k;
int res;

struct matrix {
	int x[Maxm][Maxm];
	matrix(int diag = 0) {
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				x[i][j] = (i == j) * diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				for (int l = 0; l < m; l++)
					c.x[i][j] = (c.x[i][j] + ll(x[i][l]) * ll(b.x[l][j]) % ll(mod)) % mod;
		return c;
	}
};

int Get(char c) { return islower(c)? c - 'a': 26 + c - 'A'; }

int main()
{
	scanf("%I64d %d %d", &n, &m, &k);
	matrix r = matrix(1), a;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a.x[i][j] = 1;
	char s[5];
	while (k--) {
		scanf("%s", s);
		a.x[Get(s[1])][Get(s[0])] = 0;
	}
	ll pw = n - 1ll;
	while (pw) {
		if (pw & 1ll) r = r * a;
		pw >>= 1ll; a = a * a;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			res = (res + r.x[i][j]) % mod;
	printf("%d\n", res);
	return 0;
}