#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int n;
map <int, int> M;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		res = max(res, ++M[a]);
	}
	printf("%d %d\n", res, M.size());
	return 0;
}