#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int N, K;
lld D[2][5001][51][51];
struct Z{
	int a, b;
} A[51];

int main()
{
	cin >> N;
	for (int i=1;i<=N;i++) cin >> A[i].a;
	for (int i=1;i<=N;i++) cin >> A[i].b, K += A[i].b;
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.a < b.a;
	});
	int t = 0, sum = 0, cnt = 0;
	for (int i=1;i<=N;i++){
		if (A[i-1].a != A[i].a){
			for (int j=0;j<=sum;j++) for (int p=0;p<=i;p++) for (int q=0;q<=cnt;q++)
				D[!t][j][p][q] = 1e18;
			for (int j=0;j<=sum;j++) for (int p=0;p<i;p++) for (int q=0;q<=cnt;q++) if (D[t][j][p][q] < 1e18)
				D[!t][j][p+q][0] = min(D[!t][j][p+q][0], D[t][j][p][q]);
			t ^= 1;
			cnt = 0;
		}
		cnt++;
		for (int j=0;j<=sum+A[i].b;j++) for (int p=0;p<=i;p++) for (int q=0;q<=cnt;q++)
			D[!t][j][p][q] = 1e18;
		for (int j=0;j<=sum;j++) for (int p=0;p<i;p++) for (int q=0;q<cnt;q++) if (D[t][j][p][q] < 1e18){
			D[!t][j+A[i].b][max(0, p-1)][q] = min(D[!t][j+A[i].b][max(0, p-1)][q], D[t][j][p][q]+A[i].a);
			D[!t][j][p][q+1] = min(D[!t][j][p][q+1], D[t][j][p][q]);
		}
		sum += A[i].b;
		t ^= 1;
	}
	double ans = 1e18;
	for (int i=1;i<=sum;i++)
		ans = min(ans, (double)D[t][i][0][0]/i);
	printf("%.0f\n", ceil(ans*1000));
}