#include <cstdio>
#include <stack>
using namespace std;

int n;
stack <int> S;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		while (!S.empty() && S.top() < a) { res = max(res, S.top() ^ a); S.pop(); }
		if (!S.empty()) res = max(res, S.top() ^ a);
		S.push(a);
	}
	printf("%d\n", res);
	return 0;
}