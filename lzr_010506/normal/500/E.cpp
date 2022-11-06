#include <bits/stdc++.h>
#define pb push_back
#define lowbit(x) (x&(-x))
using namespace std;
const int N = 200010;
struct node
{
	int id,y;
};
int n, m, a[N], b[N], tt[N],sta[N],tp,f[N],ans[N];
set<int> s;
set<int>::iterator it;
vector<node> v[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
void change(int x,int d)
{
	for(int i = x; i <= n; i += lowbit(i))
		tt[i] += d;
}
int find(int x)
{
	int sum = 0;
	for(int i = x; i; i -= lowbit(i))
		sum += tt[i];
	return sum;
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
	{
		a[i] = read();
		b[i] = read();
		b[i] += a[i];
	}
	m = read();
	for(int i = 1; i <= m; i ++)
	{
		int x,y;
		x = read();
		y = read();
		v[x].pb((node){i, y});
	}
	for(int i = n; i >= 1; i --)
	{
		while(tp)
			if(b[sta[tp]] <= b[i])
			{
				int x = sta[tp --];
				it = s.lower_bound(x);
				s.erase(it);
				change(x, -f[x]);
				f[x] = 0;
			}
			else break;
		if(tp)
		{
			int x = sta[tp];
			change(x, -f[x]);
			f[x] = max(0, a[x] - b[i]);
			change(x, f[x]);
		}
		sta[++ tp] = i;
		s.insert(i);
		int siz = v[i].size();
		for(int j = 0; j < siz; j ++)
		{
			int x, y = v[i][j].y, t = 0;
			t = find(y);
			it = s.lower_bound(y);
			if(it == s.end() || (*it) > y) it --;
			x = (*it);
			t += max(0, a[y] - b[x]);
			ans[v[i][j].id] = t;
		}
	}
	for(int i = 1; i <= m; i ++)
		printf("%d\n",ans[i]);
	return 0;
}