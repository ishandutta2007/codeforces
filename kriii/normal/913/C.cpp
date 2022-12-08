#include <stdio.h>
#include <map>
using namespace std;

int N; long long L,C[33];

int main()
{
	scanf ("%d %lld",&N,&L);
	for (int i=0;i<N;i++) scanf ("%lld",&C[i]);
	for (int i=1;i<N;i++){
		if (C[i] > C[i-1] * 2) C[i] = C[i-1] * 2;
	}

	long long ans = 1e18, now = 0;
	for (int i=N-1;i>=0;i--){
		long long c = L / (1ll << i);
		L %= (1 << i);
		now += c * C[i];
		if (!L) break;
		if (ans > now + C[i])
			ans = now + C[i];
	}
	if (ans > now)
		ans = now;
	printf ("%lld\n",ans);

	return 0;
}