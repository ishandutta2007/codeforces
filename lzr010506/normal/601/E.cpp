#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct thing
{
	int w,v;
	int s,e;
}ch[100001];
long long p=10000019,mod=1000000007;
int f[31][1001];
int sx[100001];
int k;
inline void cale(int l,int r,int d,vector<int> q)
{
	int i,j;
	for(i = 1; i <= k; i ++)
		f[d][i] = f[d - 1][i];
	for(i = 0; i < q.size(); i ++)
		if(ch[q[i]].s <= l && ch[q[i]].e >= r)
			for(j = k; j >= 1; j --)
				if(j >= ch[q[i]].w)
					f[d][j] = max(f[d][j], f[d][j - ch[q[i]].w] + ch[q[i]].v);
	if(l == r)
	{
		long long ans = 0;
		for(i = k; i >= 1; i --)
			ans = (ans * p + f[d][i]) % mod;
		for(i = 1; i <= sx[l]; i ++)
			printf("%I64d\n",ans);
	}
	else
	{
		int mid = (l + r) >> 1;
		vector<int> ll, rr;
		for(i = 0; i < q.size(); i ++)
		{
			if(ch[q[i]].s <= l && ch[q[i]].e >= r) continue;
			if(ch[q[i]].e <= mid) ll.pb(q[i]);
			else if(ch[q[i]].s > mid) rr.pb(q[i]);
			else ll.pb(q[i]), rr.pb(q[i]);
		}
		cale(l, mid, d + 1, ll);
		cale(mid + 1, r, d + 1, rr);
	}
}
int main()
{
	vector<int> q;
	int n;
	scanf("%d%d", &n, &k);
	int i, j;
	int v, w;
	int tot = 0,now = 1;
	for(i = 1; i <= n; i ++)
	{
		tot ++;
		scanf("%d%d",&ch[tot].v,&ch[tot].w);
		ch[tot].s = now;
	}
	int qq;
	scanf("%d", &qq);
	int x;
	while(qq --)
	{
		scanf("%d",&x);
		if(x == 1)
		{
			tot ++;
			now ++;
			scanf("%d%d", &ch[tot].v, &ch[tot].w);
			ch[tot].s = now;
		}
		else if(x == 2)
		{
			scanf("%d", &x);
			ch[x].e = now;
			now ++;
		}
		else sx[now] ++;
	}
	for(i = 1; i <= tot; i ++)
	{
		q.pb(i);
		if(ch[i].e == 0) ch[i].e = now;
	}
	cale(1,now,1,q);
	return 0;
}