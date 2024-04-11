#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n, m;
int A[Maxn], B[Maxn];
int res;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);
	int one = Inv(m);
	int two = Inv(ll(m) * m % mod);
	int larger = ll(m) * (m - 1) / 2 % mod;
	int cur = 1;
	for (int i = 0; i < n; i++)
		if (A[i] == 0 && B[i] == 0) { 
			res = (res + ll(cur) * ll(larger) % mod * two) % mod; 
			cur = ll(cur) * m % mod * two % mod; 
		} else if (A[i] != 0 && B[i] == 0) {
			res = (res + ll(cur) * ll(A[i] - 1) % mod * one) % mod;
			cur = ll(cur) * one % mod;
		} else if (A[i] == 0 && B[i] != 0) {
			res = (res + ll(cur) * ll(m - B[i]) % mod * one) % mod;
			cur = ll(cur) * one % mod;
		} else if (A[i] > B[i]) { res = (res + cur) % mod; break; }
			   else if (A[i] < B[i]) break;
	printf("%d\n", res);
	return 0;
}