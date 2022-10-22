#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 400005;

int n, k;
int a[Maxn];
map <int, int> M;
ll res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int r = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && (r == 0 || M[a[r - 1]] < k)) M[a[r++]]++;
		if (r && M[a[r - 1]] == k) res += n + 1 - r;
		M[a[l]]--;
	}
	printf("%I64d\n", res);
	return 0;
}