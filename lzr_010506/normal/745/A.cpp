#include <bits/stdc++.h>
using namespace std;
char ch[100][100];
int ans;
int main()
{
	scanf("%s", ch[0]);
	int n = strlen(ch[0]);
	ans = n;
	for(int i = 1; i < n; i ++)
	{
		for(int j = 1; j < n; j ++)
			ch[i][j] = ch[i - 1][j - 1];
		ch[i][0] = ch[i - 1][n - 1];
		bool flag = 0;
		for(int j = 0; j < i; j ++)
		{
			bool Flag = 0;
			for(int k = 0; k < n; k ++)
				if(ch[i][k] != ch[j][k]) {Flag = 1; break;}
			if(Flag == 0) {flag = 1; break;}
		}
		if(flag == 1) ans --;
	}
	cout << ans;
	return 0;
}