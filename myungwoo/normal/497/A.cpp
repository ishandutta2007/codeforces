#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[101][103];
bool w[101][101];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1;i<=N;i++) scanf("%s", A[i]+1);
	int ans = 0;
	for (int i=1;i<=M;i++){
		bool removed = 0;
		for (int j=1;j<N;j++) for (int k=j+1;k<=N;k++){
			if (!w[j][k] && A[j][i] > A[k][i]) removed = 1;
		}
		if (removed){ ans++; continue; }
		for (int j=1;j<N;j++) for (int k=j+1;k<=N;k++){
			if (A[j][i] < A[k][i]) w[j][k] = 1;
		}
	}
	printf("%d\n", ans);
}