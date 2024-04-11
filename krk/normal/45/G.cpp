#include <cstdio>
using namespace std;

const int Maxn = 6005;

int n;
int sum;
int st[Maxn];

bool Prime(int x)
{
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	scanf("%d", &n); sum = n * (n + 1) / 2;
	if (sum > 5 && sum % 2 && !Prime(sum - 2)) { st[3] = 2; sum -= 3; }
	for (int i = 1; i <= n; i++) 
		if (!st[i] && Prime(i) && Prime(sum - i)) { st[i] = 1; break; }
	for (int i = 1; i <= n; i++)
		printf("%d%c", st[i] + 1, i + 1 <= n? ' ': '\n');
	return 0;
}