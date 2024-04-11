#include <stdio.h>

const long long mod = 1000000007;

int N; long long A[202020];
long long base[202020],vec[202020];
long long inv[202020]={0,1},fact[202020]={1,1},ifact[202020]={1,1};
int main()
{

	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%lld",&A[i]);

	for (int i=2;i<=N;i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = ifact[i-1] * inv[i] % mod;
	}

	int mul[4][4] = {
		{1,},
		{1, 1},
		{1, 2, -1},
		{1, -1, 1, -1}
	};

	int v = (N-1) / 4;
	for (int i=0;i<=4*v;i+=2){
		base[i] = fact[2*v] * ifact[i/2] % mod * ifact[2*v-i/2] % mod;
	}

	int r = N-1 - 4 * v;
	for (int i=0;i<=r;i++) for (int j=0;j<=4*v;j++) vec[i+j] = (vec[i+j] + mod + mul[r][i] * base[j]) % mod;

	long long ans = 0;
	for (int i=0;i<N;i++) ans = (ans + vec[i] * A[i]) % mod;
	printf ("%lld\n",ans);

	return 0;
}