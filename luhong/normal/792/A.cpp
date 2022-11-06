#include <cstdio>
#include <algorithm>

int n, a[201000];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	int Min = 2.1e9, s = 0;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] - a[i - 1] < Min)
		{
			Min = a[i] - a[i - 1];
			s = 1;
		}
		else if(a[i] - a[i - 1] == Min)
		{
			s++;
		}
	}
	printf("%d %d\n", Min, s);
	return 0;
}