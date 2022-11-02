#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, G;
int P[MAXN], B[MAXN];
bool V[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d", P+i);
	for (int i=1;i<=N;i++) scanf("%d", B+i);
	for (int i=1;i<=N;i++) if (!V[i]){
		G++;
		for (int n=i;!V[n];n=P[n]) V[n] = 1;
	}

	int ans = G > 1 ? G : 0;
	bool flag = 0;
	for (int i=1;i<=N;i++) flag ^= B[i];
	if (!flag) ans++;

	printf("%d\n", ans);
}