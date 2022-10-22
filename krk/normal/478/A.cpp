#include <cstdio>
using namespace std;

const int Maxn = 5;

int sum;

int main()
{
	for (int i = 0; i < Maxn; i++) {
		int a; scanf("%d", &a);
		sum += a;
	}
	printf("%d\n", sum % 5? -1: sum / 5 == 0? -1: sum / 5);
	return 0;
}