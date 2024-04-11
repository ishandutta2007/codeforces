#include <cstdio>
using namespace std;

int n, k;
int res;

int Get(int n, int k)
{
	if (k == 0)
		if (n < 3) return n;
		else return 1 - n % 2;
	else if (n < 2) return n;
		 else if (n < 5) return n - 2;
		      else if (n % 2) return 0;
		      else {
		      	int g = Get(n / 2, k);
		      	if (g != 1) return 1;
		      	else return 2;
		      }
}

int main()
{
	scanf("%d %d", &n, &k); k %= 2;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		res ^= Get(a, k);
	}
	if (res) printf("Kevin\n");
	else printf("Nicky\n");
	return 0;
}