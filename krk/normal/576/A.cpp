#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> res;

bool Prime(int x)
{
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) if (Prime(i))
		for (int j = i; j <= n; j *= i)
			res.push_back(j);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}