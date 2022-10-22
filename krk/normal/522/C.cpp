#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Inf = 1000000000;

int t;
int m, k;
int a[Maxn];
int T[Maxn], R[Maxn];
int tk[Maxn];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &k);
		for (int i = 1; i <= k; i++)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 0; i < m - 1; i++) {
			scanf("%d %d", &T[i], &R[i]);
			tk[T[i]]++;
		}
		bool lack = false;
		for (int i = 0; i < m - 1; i++) {
			if (!R[i])
				if (T[i]) a[T[i]]--;
				else res++;
			else {
				if (!lack) {
					int mn = -1, val;
					for (int i = 1; i <= k; i++)
						if (!tk[i] && a[i] <= res) {
							if (mn == -1 || a[i] < val) mn = i, val = a[i];
							a[i] = 0;
						}
					res -= val;
					lack = true;
				}
				if (T[i]) a[T[i]]--;
				else res++;
			}
			tk[T[i]]--;
		}
		for (int j = 1; j <= k; j++)
			printf("%c", res >= a[j]? 'Y': 'N');
		printf("\n");
	}
	return 0;
}