#include <bits/stdc++.h>
#define db double
#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define REP(i, y) rep(i, 0, y - 1)
#define pb push_back
#define mp make_pair
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
const int N = 3e5 + 10;
const int M = 1e5;
int p[N], tp[N], t[N];
int ansx[N], ansy[N];
int w,h,n;

vector<int> lie[N], hang[N];
bool cmp(int a, int b)
{
	return p[a] < p[b];
}
int main()
{
	n = read();
	w = read();
	h = read();
	rep(i, 1, n)
	{
		tp[i] = read();
		p[i] = read();
		t[i] = read();
		if (tp[i] == 1) hang[p[i] - t[i] + M].pb(i);
		if (tp[i] == 2) lie[p[i] - t[i] + M].pb(i);
	}
	rep(i, 0, 2 * M)
	{
		int u = hang[i].size();
		int v = lie[i].size();
		sort(hang[i].begin(), hang[i].end(), cmp);
		sort(lie[i].begin(), lie[i].end(), cmp);
		rep(j, 0, u - 1)
			if (u - j <= v) ansx[hang[i][j]] = w, ansy[hang[i][j]] = p[lie[i][u - 1 - j]];
			else  ansx[hang[i][j]] = p[hang[i][v + j]], ansy[hang[i][j]] = h;

		rep(j, 0, v - 1)
			if (v - j <= u) ansx[lie[i][j]] = p[hang[i][v - 1 - j]], ansy[lie[i][j]] = h;
			else  ansx[lie[i][j]] = w, ansy[lie[i][j]] = p[lie[i][u + j]];
	}
	rep(i, 1, n)
		printf("%d %d\n", ansx[i], ansy[i]);
	return 0;
}