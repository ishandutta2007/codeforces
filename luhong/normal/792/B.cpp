#include <cstdio>
#include <algorithm>

int n, a[201000], k;
bool used[201000];

int main()
{
	scanf("%d%d", &n, &k);
	int s = n; 
	int j = 1;
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &a[i]);
		a[i] %= s;
		while(a[i] >= 1)
		{
			if(!used[j]) j++, a[i]--;
			else j++;
			if(j == n + 1) j = 1;
		}
		while(used[j])
		{
			j++;
			if(j == n + 1) j = 1;
		}
		printf("%d ", j);
		used[j] = 1;
		j++; if(j == n + 1) j = 1;
		s--;
	}
	return 0;
}