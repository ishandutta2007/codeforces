#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 310000


int main() {
	vector<int>a;
	bool used[N];
	int n, k, t, m;
	int x, y;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, 3*n)used[i] = false;
		a.clear();
		f(i, m) {
			scanf("%d %d", &x, &y);
			x--;
			y--;
			if ((!used[x]) && (!used[y])) {
				a.push_back(i + 1);
				used[x] = true;
				used[y] = true;
			}
		}
		if (a.size() >= n) {
			printf("Matching\n");
			f(i, n) {
				printf("%d", a[i]);
				if (i < (n - 1))printf(" ");
				else printf("\n");
			}
		}
		else {
			printf("IndSet\n");
			k = 0;
			f(i, 3 * n) {
				if (!used[i]) {
					printf("%d", i + 1);
					k++;
					if (k < n)printf(" ");
					else {
printf("\n");
                      break;
                    }
				}
			}
		}
	}


	return 0;
}