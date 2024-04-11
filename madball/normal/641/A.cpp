#include <stdio.h>

char str[100005];
int ju[100005];

bool u[100005];

int main()
{
	int n, m, k;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &str[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ju[i]);
		if (str[i] == '<')
			ju[i] = -ju[i];
	}
	int c = 0;
	while (!u[c])
	{
		u[c] = true;
		c += ju[c];
		if (c < 0 || c >= n)
		{
			printf("FINITE");
			return 0;
		}
	}
	printf("INFINITE");

}