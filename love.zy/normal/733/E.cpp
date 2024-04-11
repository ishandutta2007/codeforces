#include<cstdio>
int n;
char s[2][1000002];
long long ans[1000002];
int pos[1000002];
int solve(char s[])
{
	int left = 0;
	s[0] = 'D';
	for (int i = 0; i <= n + 1; i++){
		if (s[i] == 'D')pos[left++] = i;
	}
	for (int i = 1; i < left; i++)
		ans[i] = ans[i - 1] + (pos[i] - i) * 2 + 1;
	return left;
}
int main()
{
	int len;
	scanf("%d%s", &n, s[0] + 1);
	len = solve(s[0]);
	for (int i = 1; i < len; i++)
		printf("%I64d\n", ans[i]);
	for (int i = 1; i <= n; i++)
		s[1][i] = s[0][n + 1 - i] == 'D' ? 'U' : 'D';
	len = solve(s[1]);
	for (int i = len - 1; i > 0; i--)
		printf("%I64d\n", ans[i]);
	return 0;
}