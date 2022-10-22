#include <cstdio>
using namespace std;

int n;
int val = -1;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		while (a % 2 == 0) a /= 2;
		while (a % 3 == 0) a /= 3;
		if (val == -1) val = a;
		else if (val != a) { printf("No\n"); return 0; }
	}
	printf("Yes\n");
	return 0;
}