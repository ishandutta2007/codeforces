#include <bits/stdc++.h>
using namespace std;
char ch[510][510];
int n, m, l, r;
int a[510][510];
bool flag;
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%s", ch[i] + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(ch[i][j] == 'X')
			{
				while(ch[i + l + 1][j] == 'X') l ++;
				while(ch[i][j + r + 1] == 'X') r ++;
				for(int x = i; x <= i + l; x ++)
					for(int y = j; y <= j + r; y ++)
						if(ch[x][y] == '.') {cout << "NO"; return 0;}
						else a[x][y] = 1;
				for(int x = 1; x <= n; x ++)
					for(int y = 1; y <= m; y ++)
						if(ch[x][y] == 'X' && a[x][y] == 0) {cout << "NO"; return 0;}
				cout << "YES";
				return 0;
			}
}