#include <bits/stdc++.h>
using namespace std;
int ans;
int ch[5], a[200010];
char C[200010];
int main()
{
	int n;
	cin >> n;
	scanf("%s", C);
	for(int i = 0; i < n; i ++)
	{
		if(C[i] == 'U') a[i + 1] = 1;
		if(C[i] == 'D') a[i + 1] = 2;
		if(C[i] == 'L') a[i + 1] = 3;
		if(C[i] == 'R') a[i + 1] = 4;
	}
	ans = 1;
	for(int i = 1; i <= n; i ++)
	{
		int now = a[i];
		if(now == 1)
		{
			if(ch[2]) {ans ++; memset(ch, 0, sizeof(ch)); ch[1] = 1;continue;}
			ch[1] ++;
		}
		if(now == 2)
		{
			if(ch[1]) {ans ++; memset(ch, 0, sizeof(ch)); ch[2] = 1;continue;}
			ch[2] ++;
		}
		if(now == 3)
		{
			if(ch[4]) {ans ++; memset(ch, 0, sizeof(ch)); ch[3] = 1;continue;}
			ch[3] ++;
		}
		if(now == 4)
		{
			if(ch[3]) {ans ++; memset(ch, 0, sizeof(ch)); ch[4] = 1;continue;}
			ch[4] ++;
		}
	}
	cout << ans;
	return 0;
}