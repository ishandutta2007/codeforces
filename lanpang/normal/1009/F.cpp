#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

struct mmp{
	int ls , rs , x , d;
}tr[maxn*25];
int n , ans[maxn] , rt[maxn] , tp , d[maxn];
vector<int> v[maxn];

int best(int x , int y)
{
	if (!y) return x;
	if (!x) return y;
	if (tr[x].x > tr[y].x || (tr[x].x == tr[y].x && tr[x].d < tr[y].d)) return x;
	else return y;
}

void ins(int &num , int l , int r , int x)
{
	if (!num) 
	{
		num = ++tp;
		if (l == r) tr[num].d = l;
	}
	if (l == r)
	{
		tr[num].x += 1;
		return;
	}
	int mid = ((l+r)>>1);
	if (x <= mid) ins(tr[num].ls,l,mid,x);
	else ins(tr[num].rs,mid+1,r,x);
	int gg = best(tr[num].ls,tr[num].rs);
	tr[num].x = tr[gg].x;
	tr[num].d = tr[gg].d;
}

void merge(int &num1 , int num2 , int l , int r)
{
	if (!num2) return;
	if (!num1)
	{
		num1 = num2;
		return;
	}
	if (l == r)
	{
		tr[num1].x += tr[num2].x;
		return;
	}
	int mid = ((l+r)>>1);
	merge(tr[num1].ls,tr[num2].ls,l,mid);
	merge(tr[num1].rs,tr[num2].rs,mid+1,r);
	int gg = best(tr[num1].ls,tr[num1].rs);
	tr[num1].x = tr[gg].x;
	tr[num1].d = tr[gg].d;
}

void dfs(int x , int y)
{
	d[x] = d[y]+1;
	ins(rt[x],1,n,d[x]);
	if (v[x].size() == 1 && (n == 1 || x != 1)) return;
	for (auto to: v[x])
	{
		if (to != y) 
		{
			dfs(to,x);
			merge(rt[x],rt[to],1,n);
		}
	}
	ans[x] = tr[rt[x]].d-d[x];
}

int main()
{
	int i , j , x , y;
	cin >> n;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for (i = 1 ; i <= n ; i++)
		printf("%d\n",ans[i]);
	return 0;
}