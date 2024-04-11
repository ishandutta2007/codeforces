#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 2000000000000000000ll;
const int Maxn = 205;

ll sum[Maxn], cnt[Maxn];
ll a;
int num[Maxn];
ll dsum, got;

ll Mult(ll a, ll b)
{
	if (a <= Inf / b) return a * b;
	return Inf;
}

ll Add(ll a, ll b)
{
	return min(a + b, Inf);
}

void calcCnt()
{
	cnt[0] = 1;
	for (int i = 1; i < Maxn; i++)
		cnt[i] = Mult(cnt[i - 1], 10ll);
}

void calcSum()
{
	sum[0] = 0;
	for (int i = 1; i < Maxn; i++)
		sum[i] = Add(Mult(cnt[i - 1], 45ll), Mult(sum[i - 1], 10ll));
}

ll Dsum(ll x)
{
	ll sum = 0;
	while (x) { sum += x % 10; x /= 10; }
	return sum;
}

void Inc()
{
	for (int i = 1; i < Maxn; i++)
		if (num[i] < 9) { num[i]++; dsum++; break; }
		else { num[i] = 0; dsum -= 9; }
}

void Dec()
{
	int pnt = 1;
	while (num[pnt] == 0) pnt++;
	num[pnt]--;
	for (int i = 1; i < pnt; i++) num[i] = 9;
}

int main()
{
	calcCnt(); calcSum();
	scanf("%I64d", &a);
	for (int i = Maxn - 1; i >= 1; i--) {
		ll cur = 0;
		while (Add(got, Add(Mult(dsum + cur, cnt[i - 1]), sum[i - 1])) <= a) {
			got = Add(got, Add(Mult(dsum + cur, cnt[i - 1]), sum[i - 1]));
			cur++;
		}
		num[i] = cur; dsum += cur;
	}
	ll l = 1;
	while (got != a)
		if (got < a) { got += dsum; Inc(); }
		else { got -= Dsum(l); l++; }
	printf("%I64d ", l);
	Dec();
	int pnt = Maxn - 1;
	while (num[pnt] == 0) pnt--;
	for (int i = pnt; i > 0; i--)
		printf("%d", num[i]);
	printf("\n");
	return 0;
}