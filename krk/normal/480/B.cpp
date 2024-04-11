#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int lim = 2000000007;

int n, l, x, y;
int a[Maxn];
set <int> S;

int Add(int a, int b)
{
	if (ll(a) + ll(b) > ll(lim)) return lim;
	return a + b;
}

int checkFirst(int dist)
{
	for (int i = 1; i <= n; i++)
		if (S.find(Add(a[i], dist)) != S.end())
			return i;
	return -1;
}

int checkLast(int dist)
{
	for (int i = n; i >= 1; i--)
		if (S.find(a[i] - dist) != S.end())
			return i;
	return -1;
}

bool checkSpecial(int &res)
{
	int f = checkFirst(x + y);
	if (f != -1) { res = a[f] + y; return true; }
	f = checkFirst(y - x);
	if (f != -1 && a[f] + y <= l) { res = a[f] + y; return true; }
	f = checkLast(y - x);
	if (f != -1 && a[f] - y >= 0) { res = a[f] - y; return true; }
	return false;
}

int main()
{
	scanf("%d %d %d %d", &n, &l, &x, &y);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		S.insert(a[i]);
	}
	int g = checkFirst(x), b = checkFirst(y);
	if (g != -1 && b != -1) printf("0\n");
	else if (g != -1 || b != -1) {
			printf("1\n");
			if (g != -1) printf("%d\n", y);
			else printf("%d\n", x);
		 } else {
		 	int res;
		 	if (checkSpecial(res)) {
		 		printf("1\n");
		 		printf("%d\n", res);
		 	} else {
		 		printf("2\n");
		 		printf("%d %d\n", x, y);
		 	}
		 }
	return 0;
}