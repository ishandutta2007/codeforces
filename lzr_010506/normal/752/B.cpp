#include <bits/stdc++.h>
using namespace std;
char ch1[1010], ch2[1010];
struct Ans
{
	char x, y;
}ans[30];
int s, a[30], Ans;
int main()
{
	scanf("%s%s", ch1, ch2);
	int n = strlen(ch1);
	for(int i = 0; i < n; i ++)
	{
		bool flag = 0;
		for(int j = 1; j <= s; j ++)
		{
			if(ans[j].x == ch1[i] && ans[j].y == ch2[i]) {flag = 1; break;}
			if(ans[j].x == ch2[i] && ans[j].y == ch1[i]) {flag = 1; break;}
			if(ans[j].x == ch1[i] || ans[j].x == ch2[i] || ans[j].y == ch1[i] || ans[j].y == ch2[i]) {cout << -1; return 0;}
		}
		if(flag == 0) ans[++ s].x = ch1[i], ans[s].y = ch2[i];
	}
	int Ans = s;
	for(int i = 1; i <= s; i ++)
        if(ans[i].x == ans[i].y) Ans --, a[i] = 1;
	cout << Ans << endl;
	for(int i = 1; i <= s; i ++)
		if(a[i] == 0)cout << ans[i].x << " " << ans[i].y << endl;
	return 0;
}