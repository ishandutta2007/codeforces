#include <bits/stdc++.h>
using namespace std;

int N, H;

int main()
{
	scanf("%d%d", &N, &H);
	int ans = N;
	for (int i=1;i<=N;i++){
		int v; scanf("%d", &v);
		if (v > H) ans++;
	}
	printf("%d\n", ans);
}