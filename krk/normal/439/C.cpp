#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n, k, p;
int a[Maxn];
vector <vector <int> > V;

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	V.resize(k);
	int odd = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); odd += a[i] % 2;
	}
	if (odd < k - p || odd % 2 != (k - p) % 2) printf("NO\n");
	else {
		int lef = (odd - (k - p)) / 2 + n - odd;
		if (lef < p) { printf("NO\n"); return 0; }
		int ind = 0, cnt = 0;
		for (int i = 0; i < n; i++)
			if (a[i] % 2) {
				V[ind].push_back(a[i]);
				if (ind != k - 1)
					if (ind < k - p) ind++;
					else if (cnt == 0) cnt++;
				     	 else { 
				     		ind++; 
				     		cnt = 0; 
				     	 }
			}
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0) {
				V[ind].push_back(a[i]);
				if (ind != k - 1) ind++;
			}
		printf("YES\n");
		for (int i = 0; i < k; i++) {
			printf("%d", V[i].size());
			for (int j = 0; j < V[i].size(); j++)
				printf(" %d", V[i][j]);
			printf("\n");
		}
	}
	return 0;
}