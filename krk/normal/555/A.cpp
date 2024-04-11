#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, k;
int col[Maxn];
int lst = 1;
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int cnt; scanf("%d", &cnt);
		res += cnt - 1;
		while (cnt--) {
			int num; scanf("%d", &num);
			col[num] = i;
		}
	}
	int lst = 1;
	while (col[lst] == col[1]) lst++;
	lst--;
	res -= lst - 1;
	res += n - lst;
	printf("%d\n", res);
	return 0;
}