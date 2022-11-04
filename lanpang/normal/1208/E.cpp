#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e6+10;
const LL mod = 1e9+7;

int m , l , n , tp , la , b[maxn];
LL f[maxn] , a[maxn] , lla;
struct mmp{
	int i;
	bool operator < (const mmp &op) const{
		return a[i] < a[op.i];
	}
}ff;
priority_queue<mmp> pq;
struct gkd{
	int i , p;
	bool operator < (const gkd &op) const{
		return p < op.p;
	}
}gg , q[maxn];

int main()
{
	int i , j , ii;
	cin >> m >> l;
	l += 2;
	for (j = 1 ; j <= m ; j++)
	{
		scanf("%d",&n);
		n += 2;
		a[1] = a[n] = 0; 
		for (i = 2 ; i < n ; i++)
			scanf("%I64d",&a[i]);
		tp = 0;
		for (i = 1 ; i <= n ; i++)
		{
			b[i] = 0;
			gg.i = i;
			gg.p = i;
			q[++tp] = gg;
			gg.p = l-n+i+1;
			q[++tp] = gg;
		}
		sort(q+1,q+tp+1);
		while (!pq.empty()) pq.pop();
		la = 1;
		lla = 0;
		for (i = 1 ; i <= tp ; i++)
		{
			if (q[i].p > l) break;
			for (ii = i ; ii <= tp && q[ii].p == q[i].p ; ii++)
			{
				b[q[ii].i] ^= 1;
				if (b[q[ii].i])
				{
					ff.i = q[ii].i;
					pq.push(ff);
				}
			}
			i = ii-1;
			while (!b[pq.top().i]) pq.pop();
			f[la] += lla;
			f[q[i].p] -= lla;
			la = q[i].p;
			lla = a[pq.top().i];
		}
		f[la] += lla;
	}
	for (i = 2 ; i < l ; i++)
	{
		f[i] += f[i-1];
		printf("%I64d ",f[i]); 
	}
	printf("\n");
	return 0;
}