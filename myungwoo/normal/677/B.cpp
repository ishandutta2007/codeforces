#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long lld;

int N, H, K;
int A[MAXN];

int main()
{
	scanf("%d%d%d", &N, &H, &K);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	int r = H; lld ans = 0;
	for (int i=1;i<=N;i++){
		if (r < A[i]){
			int v = A[i]-r, t = (v-1)/K+1;
			ans += t;
			r = min(r+t*K, H);
		}
		r -= A[i];
	}
	if (r < H){
		int v = H-r, t = (v-1)/K+1;
		ans += t;
	}
	printf("%lld\n", ans);
}