#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxl = 26;
const int Maxn = 100005;

int n;
char str[Maxn];
int freq[Maxl];
int bst = -1, cnt;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		freq[str[i] - 'A']++;
	for (int i = 0; i < Maxl; i++) {
		if (freq[i] > bst) bst = freq[i], cnt = 0;
		if (freq[i] == bst) cnt++;
	}
	printf("%d\n", toPower(cnt, n));
	return 0;
}