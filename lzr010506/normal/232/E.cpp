#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;
#define N 510
struct node
{
	int x1,y1,x2,y2;
	bool ans;
};
node q[600100];
bitset<N> f1[N][N], f2[N][N];
char ch[N][N];
int n, m, Q;

void solve(int l, int r, vi L)
{
	if (l > r) return;
	if (L.size() == 0) return;
	int mid = (l + r) >> 1;
	
	for(int i = l - 1; i <= r + 1; i ++)
		for(int j = 0; j <= m + 1; j ++)
			f1[i][j].reset(), f2[i][j].reset();
	
	for(int j = 1; j <= m; j ++)
		if (ch[mid][j] == '.')
			f1[mid][j].set(j), f2[mid][j].set(j);
	for(int i = mid; i >= l; i --)
		for(int j = m; j >= 1; j --)
		{
			if (ch[i][j] == '#') continue;
			f1[i][j] |= f1[i][j + 1];
			f1[i][j] |= f1[i + 1][j];
		}
	
	for(int i = mid; i <= r; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if (ch[i][j] == '#') continue;
			f2[i][j] |= f2[i][j - 1];
			f2[i][j] |= f2[i - 1][j];
		}
	
	vi lL,rL;
	for(int i = 0; i < L.size(); i ++)
	{
		if (q[L[i]].x2 < mid) lL.pb(L[i]);
		else if (q[L[i]].x1 > mid) rL.pb(L[i]);
		else q[L[i]].ans = (f1[q[L[i]].x1][q[L[i]].y1]&f2[q[L[i]].x2][q[L[i]].y2]).any();
	}
	
	solve(l, mid, lL);
	solve(mid + 1, r, rL);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i ++)
		scanf("%s",ch[i] + 1);
	
	scanf("%d",&Q);
	for(int i = 1; i <= Q; i ++)
	{
		scanf("%d%d%d%d",&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2);
		q[i].ans = 0;
	}
	
	vi L;
	for(int i = 1; i <= Q; i ++)
		L.pb(i);
	
	solve(1,n,L);
	
	for(int i = 1; i <= Q; i ++)
		if (q[i].ans) puts("Yes"); 
		else puts("No");
	
	return 0;
}