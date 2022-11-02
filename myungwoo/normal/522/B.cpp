#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, W[MAXN], H[MAXN];

int main()
{
	scanf("%d", &N);
	int w_sum = 0, h_max1 = 0, h_max2 = -1;
	for (int i=1;i<=N;i++){
		scanf("%d%d", W+i, H+i);
		w_sum += W[i];
		if (h_max1 < H[i]) h_max2 = h_max1, h_max1 = H[i];
		else if (h_max2 < H[i]) h_max2 = H[i];
	}
	for (int i=1;i<=N;i++){
		int w = w_sum - W[i], h = h_max1 == H[i] ? h_max2 : h_max1;
		printf("%d ", w*h);
	} puts("");
}