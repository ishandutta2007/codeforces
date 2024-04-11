#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
int n, m, flag;
char ch[110][110];
int main()
{
	cin >> n >> m;
	rep(i, 1, n) scanf("%s", ch[i] + 1);
	if(n % 3 == 0)
	{
		rep(i, 1, n)
			rep(j, 1, m)
			{
				if(ch[i][j] != ch[(i - 1) / (n / 3) * (n / 3) + 1][1]) {flag = 1; break;}
				rep(k, 1, 3)
					if((i + (n / 3) - 1) / (n / 3) != k && ch[i][j] == ch[k * (n / 3) - (n / 3) + 1][1]) {flag = 1; break;}
			}
		if(!flag) { puts("YES"); return 0; }
	}
	flag = 0;
	swap(n, m);
	if(n % 3 == 0)
	{
		rep(i, 1, n)
			rep(j, 1, m)
			{
				if(ch[j][i] != ch[1][(i - 1) / (n / 3) * (n / 3) + 1]) { flag = 1; break; }
				rep(k, 1, 3)
					if((i + (n / 3) - 1) / (n / 3) != k && ch[j][i] == ch[1][k * (n / 3) - (n / 3) + 1]) {flag = 1; break;}
			}
		if(!flag){ puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}