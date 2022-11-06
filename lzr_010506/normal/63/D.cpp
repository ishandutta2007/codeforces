#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 500;
char s[N][N];
int a, b, c, d, n, x;
vector< pair<int, int> > v;
int main() 
{
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
	for (int i = 0; i < b || i < d; i ++) 
	{
		for (int j = 0; j < a + c; j ++) 
			s[i][j] = '.';
		s[i][a + c] = '\0';
	}
	for (int j = 0; j < a + c; j ++) 
		if ((j - a) % 2 == 0) 
			for (int i = 0; i < (j < a ? b : d); i ++) 
				v.pb(mp(i, j));
		else 
			for (int i = (j < a ? b : d) - 1; i >= 0; i --)
				v.pb(mp(i, j));

	for (int i = 0; i < n; i ++) 
	{
		scanf("%d", &x);
		for (int j = 0; j < x; j ++) 
		{
			s[v.back().first][v.back().second] = 'a' + i;
			v.pop_back();
		}
	}
	puts("YES");
	for (int i = 0; i < b || i < d; i ++) puts(s[i]);
	return 0;
}