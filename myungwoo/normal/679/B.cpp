#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld M, X, Y;

lld p3(lld n){ return n * n * n; }

void dfs(lld m, lld cnt, lld v)
{
	if (m == 0){
		if (X < cnt || X == cnt && Y < v) X = cnt, Y = v;
		return;
	}
	int x = 1;
	while (p3(x+1) <= m) x++;
	dfs(m - p3(x), cnt+1, v + p3(x));
	if (x > 1)
		dfs(p3(x)-1-p3(x-1), cnt+1, v + p3(x-1));
}

int main()
{
	cin >> M;
	dfs(M, 0, 0);
	cout << X << " " << Y << endl;
}