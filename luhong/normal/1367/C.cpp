#include <cstdio>

char s[201000];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		scanf("%s", s);
		int sum = k, ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0') sum++;
			else ans += (sum - k) / (k + 1), sum = 0;
		}
		ans += sum / (k + 1);
		printf("%d\n", ans);
	}
}