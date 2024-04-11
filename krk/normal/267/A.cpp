#include <cstdio>
using namespace std;

int n;
int a, b;

int Ops(int a, int b) { return a? b / a + Ops(b % a, a): 0; }

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", Ops(a, b));
	}
	return 0;
}