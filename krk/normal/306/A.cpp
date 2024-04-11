#include <cstdio>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = m; i >= 1; i--) {
		int give = n / i; n -= give;
		printf("%d%c", give, i - 1 >= 1? ' ': '\n');
	}
	return 0;
}