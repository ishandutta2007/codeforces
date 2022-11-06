#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}


const int N = 1010;
struct P
{
	int val;
	int id[2];
}p[N*N];
int m;

int Id(int i,int j)
{
	return i * m + j;
}

inline void Goto(int& pos,int x,int y)
{
	rep(i, 1, x - 1) pos = p[pos].id[1];
	rep(i, 1, y - 1) pos = p[pos].id[0];
}

inline void shift(int p1, int p2,int h,int w,int s)
{
	rep(i, 0, h - 1)
	{
		p1 = p[p1].id[s];
		p2 = p[p2].id[s];
		swap(p[p1].id[1 - s], p[p2].id[1 - s]);
	}
	s = 1 - s;
	rep(i, 0, w - 1)
	{
		p1 = p[p1].id[s];
		p2 = p[p2].id[s];
		swap(p[p1].id[1 - s], p[p2].id[1 - s]);
	}
}

int	main()
{
	int n,q;
	n = read();
	m = read();
	q = read();
	rep(i, 1, n)
		rep(j, 1, m)
			p[Id(i, j)].val = read();
	rep(i, 0, n)
		rep(j, 0, m)
		{
			p[Id(i, j)].id[0] = Id(i, j  +1);
			p[Id(i, j)].id[1] = Id(i + 1, j);
		}
	int x1,x2,y1,y2,h,w;
	while(q --)
	{
		x1 = read();
		y1 = read();
		x2 = read();
		y2 = read();
		h = read();
		w = read();
		int p1 = 0, p2 = 0;
		Goto(p1, x1, y1);
		Goto(p2, x2, y2);
		shift(p1, p2, h, w, 1);
		shift(p1, p2, w, h, 0);
	}
	int pos=0;
	rep(i, 1, n)
	{
		pos = p[pos].id[1];
		int tmp = pos;
		rep(j, 1, m)
		{
			tmp=p[tmp].id[0];
			printf("%d ",p[tmp].val);
		}
		puts("");
	}
	return 0;
}