#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int BIT[Maxn];
int n;
int res;

int Get(int x)
{
	int res = 0;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

void Set(int x)
{
	for (int i = x; i > 0; i -= i & -i)
		BIT[i]++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		res = (res + Get(a + 1)) % 2;
		Set(a);
	}
	if (n % 2 && res % 2 || n % 2 == 0 && res % 2 == 0)
		printf("Petr\n");
	else printf("Um_nik\n");
	return 0;
}