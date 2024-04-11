#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, M;
int L[MAXN], R[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1;i<=M;i++) scanf("%d%d", L+i, R+i);
	int ans = N;
	for (int i=1;i<=M;i++)
		ans = min(ans, R[i]-L[i]+1);
	printf("%d\n", ans);
	for (int i=1;i<=N;i++) printf("%d ", i % ans); puts("");
}