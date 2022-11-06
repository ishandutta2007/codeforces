#include <cstdio>

int n;
int cnt[101000], a[101000];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]); cnt[a[i]]++;
	}
	int sum = 0, id = -1;
	for(int i = 1; i <= 100; i++)
	{
		if(cnt[i] == 1) sum++;
		if(cnt[i] >= 3) id = i;
	}
	if((sum & 1) && id == -1) return 0 * puts("NO");
	puts("YES");
	bool t = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[a[i]] == 1) printf(t == 1 ? "B" : "A"), t ^= 1;
		else if(cnt[a[i]] >= 3)
		{
			if(id != -1)
			{
				if(sum & 1) printf("B"), id = -1;
				else printf("A");
			}
			else printf("A");
		}
		else printf("A");
	}
	return 0;
}