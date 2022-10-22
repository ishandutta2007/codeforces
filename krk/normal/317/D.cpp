#include <cstdio>
#include <set>
using namespace std;

const int Maxp = 31;
const int num[Maxp] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

int n;
set <int> taken;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 2; i * i <= n; i++) if (!taken.count(i)) {
		int cur = 1, cnt = 0;
		while (cur <= n / i) { cur *= i; taken.insert(cur); cnt++; }
		res ^= num[cnt];
	}
	if ((n - taken.size()) % 2) res ^= 1;
	printf("%s\n", res? "Vasya": "Petya");
	return 0;
}