#include <bits/stdc++.h>
using namespace std;

int N;
int A[101], D[101][4];

int main()
{
	cin >> N;
	for (int i=1;i<=N;i++) cin >> A[i];
	for (int i=1;i<=N;i++) for (int j=0;j<4;j++) D[i][j] = 2e9;
	for (int i=0;i<N;i++) for (int j=0;j<4;j++) if (D[i][j] < 2e9){
		for (int k=0;k<4;k++) if ((j&k) == 0 && (A[i+1]&k) == k){
			D[i+1][k] = min(D[i+1][k], D[i][j] + (k ? 0 : 1));
		}
	}
	int ans = 2e9;
	for (int i=0;i<4;i++) ans = min(ans, D[N][i]);
	printf("%d\n", ans);
}