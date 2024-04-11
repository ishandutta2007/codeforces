#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int T, N, K;
int A[MAXN], D[MAXN], P[MAXN];
int nxt[MAXN], rec[MAXN];

int main()
{
	//for (scanf("%d", &T);T--;){
		scanf("%d%*d%d", &N, &K);
		for (int i=1;i<=N;i++) scanf("%d", A+i);

		int ans = 0;
		for (int i=1;i<=N;i++){
			nxt[rec[A[i]]] = i;
			D[A[i]]++; if (!rec[A[i]]) P[A[i]] = i;
			while (i-P[A[i]]+1 - D[A[i]] > K){
				P[A[i]] = nxt[P[A[i]]]; D[A[i]]--;
			}
			ans = max(ans, D[A[i]]);
			rec[A[i]] = i;
		}

		//static int ts = 0;
		printf("%d\n", ans);
	//}
}