#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 505;

int n;
int A[Maxn][Maxn];
int x[Maxn];
bool del[Maxn];
ll sum;
ll res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &A[i][j]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]); del[x[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!del[i] && !del[j]) sum += A[i][j];
	for (int add = n - 1; add >= 0; add--) {
		int v = x[add];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (A[i][v] + A[v][j] < A[i][j]) {
					if (!del[i] && !del[j]) sum -= A[i][j];
					A[i][j] = A[i][v] + A[v][j]; 
					if (!del[i] && !del[j]) sum += A[i][j];
				}
		for (int i = 1; i <= n; i++) 
			if (!del[i]) sum += A[i][v] + A[v][i];
		del[v] = false;
		res[add] = sum;
	}
	for (int i = 0; i < n; i++)
		printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}