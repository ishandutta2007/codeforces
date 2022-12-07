#include<cstdio>
#define ll long long
using namespace std;
const ll P = 1e9 + 7;
const int N = 1e7 + 1;
int M;
ll mu[N], f[N], pow2[N], r;
int main()
{
	scanf("%d", &M);
	for(int i = 0, x; i < M; i++)
	{
		scanf("%d", &x);
		f[x] ++;
	}
	pow2[0] = 1;
	for(int i = 1; i < N; i++)
		pow2[i] = 2 * pow2[i - 1] % P;
	mu[1] = 1;
	for(int i = 1; i < N; i ++)
	{
		for(int j = 2 * i; j < N; j += i) 
		{
			mu[j] -= mu[i];
			f[i] += f[j];
		}
		if(!f[i]) continue;
		r = (r + (2 * (pow2[f[i] - 1]) * f[i] - M * (pow2[f[i]] - 1)) * mu[i] % P + P) % P;
	}
	printf("%I64d\n", r);
	return 0;
}