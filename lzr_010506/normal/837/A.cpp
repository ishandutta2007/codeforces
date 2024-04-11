#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
int n;
char ch;
int main()
{
	scanf("%d\n", &n);
	int ans = 0, now = 0;
	rep(i, 1, n)
	{
		ch = getchar();
		if(ch == ' ') ans = max(ans, now), now = 0;
		if(ch >= 'A' && ch <= 'Z') now ++;
	}
	ans = max(ans, now);
	cout << ans;
	return 0;
}