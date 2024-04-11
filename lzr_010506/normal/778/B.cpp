#include <bits/stdc++.h>
#define str string
using namespace std;
struct node
{
	int	a,x,y,b[1010];
	str s;
}a[5010];
int n, m, cnt, Rt;
char Min[1010], Max[1010];
str s;
map<str, int> Dy;

int	Find(int x)
{
	if(a[x].a >= 0) return a[x].a;
	int g = Find(a[x].x);
	int l = Find(a[x].y);
	if(a[x].s[0] == 'O') return	a[x].a = g | l;
	if(a[x].s[0] == 'X') return	a[x].a = g ^ l;
	return a[x].a = g & l;
}

int	main()
{
	cin >> n >> m;
	for(int	i = 1; i <= n + 1; i ++)
        for(int j = 0; j <= m + 1; j ++)
            a[i].b[j] = -1;
	for(int	i = 1; i <= n; i ++)
	{
		cin >> s;
		Dy[s] = ++ cnt;
		int	x = Dy[s];
		cin >> s;
		cin >> s;
		if(s[0] < '2' && s[0] >= '0')
			for(int	j = 0; j < m; j ++)
				a[x].b[j] = s[j] - '0';
		else
		{
			if(!Dy[s]) Dy[s] = ++ cnt;
			if(s[0] == '?') Rt = Dy[s];
			a[x].x = Dy[s];
			cin >> a[x].s;
			cin >> s;
			if(!Dy[s]) Dy[s] = ++ cnt;
			if(s[0] == '?')Rt = Dy[s];
			a[x].y = Dy[s];
		}
	}
	for(int	i = 0; i < m; i ++)
	{
		a[Rt].b[i] = 0;
		for(int k = 1; k <= cnt; k ++)
			a[k].a = a[k].b[i];
		int	ans = 0;
		for(int k = 1; k <= cnt; k ++)
			if(k != Rt)ans += Find(k);
		int	x = ans;
		a[Rt].b[i] = 1;
		for(int k = 1; k <= cnt; k ++)
			a[k].a = a[k].b[i];
		ans = 0;
		for(int k = 1; k <= cnt; k ++)
			if(k != Rt)ans += Find(k);
		int	y = ans;
		if(x < y) Min[i] = '0', Max[i] = '1';
		else if(x > y)Min[i] = '1',Max[i] = '0';
		else Min[i] = Max[i] = '0';
	}
	puts(Min);
	puts(Max);
	return	0;
}