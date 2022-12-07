#include <bits/stdc++.h>
#define N 200010
#define pb push_back
#define P 1000000007
using namespace std;
vector<int> b[N];
int L[N],R[N],u[N],v[N],opt[N],size[N];
int m,n,ql,qr,upd,tot,now,ans,i,x;
struct data
{
    int cnt,sum;
    data()
	{
		cnt = 1;
	}
    void multi(int x)
	{
        cnt = 1ll * cnt * x % P;
        sum = 1ll * sum * x % P;
  	}
	int renew(int x)
	{
		cnt = 1;
		sum = x;
		return 0;
	}
}a[N<<2];

void DFS(int x,int Fa)
{
    L[x] = ++ tot;
    for (int i = 0, y; i < b[x].size(); i ++)
        if ((y = b[x][i]) != Fa)
            DFS(y,x);
    R[x] = tot;
}
int INV(int a)
{
    int ret = 1, b = P - 2;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1) ret = 1ll * ret * a % P;
    return ret;
}

inline void down(int x)
{
    if(a[x].cnt == 1) return;
    a[x << 1].multi(a[x].cnt);
    a[x << 1 | 1].multi(a[x].cnt);
	a[x].cnt = 1;
}
inline void up(int x)
{
	a[x].sum = ( a[x << 1].sum + a[x << 1 | 1].sum) % P;
}

void Multi(int x,int l,int r)
{
    if (ql <= l && r <= qr)
	{
        a[x].multi(now);
		return;
  	}
	int mid = (l + r) >> 1;
	down(x);
  	if(ql <= mid) Multi(x << 1, l, mid);
  	if(qr > mid)  Multi(x << 1 | 1, mid + 1, r);
	up(x);
}
int Update(int x,int l,int r,int pos)
{
    if (l == r) return (!upd)?a[x].sum:a[x].renew(now);
    int mid = (l + r) >> 1;
	down(x);
    int ret = (pos <= mid) ? Update(x << 1, l, mid, pos): Update(x << 1 | 1, mid + 1, r, pos);
    return up(x),ret;
}
void Query(int x,int l,int r)
{
    if (ql <= l && r <= qr)
	{
        ans = (ans + a[x].sum) % P;
        return;
  	}
	int mid = (l + r) >> 1;
	down(x);
  	if (ql <= mid) Query(x << 1, l, mid);
  	if (qr > mid)  Query(x << 1 | 1, mid + 1, r);
}
int main()
{
    scanf("%d%d",&v[1],&m);
	n = 1;
    for (int i = 1; i <= m; i ++)
	{
        scanf("%d%d",&opt[i],&u[i]);
        if(opt[i] == 1) 
        {
			scanf("%d",&v[++ n]);
			b[u[i]].pb(n);
		}
  	}
	DFS(1,0);
	size[n = 1] = 1;
  	upd = 1;
	now = v[1];
	Update(1, 1, tot, L[1]);
  	for (int i = 1; i <= m; i ++)
    	if (opt[i] == 1)
		{
        	x = u[i];
			size[++ n] = 1;
			ql = L[x];
			qr = R[x];
			now = 1ll * (size[x] + 1) * INV(size[x]) % P;
			size[x] ++;
            Multi(1, 1, tot);
            upd = 0;
            now = Update(1, 1, tot, L[x]);
            now = 1ll * now * INV(v[x]) % P;
            now = 1ll * now * v[n] % P;
            upd = 1;
			Update(1, 1, tot, L[n]);
    	}
		else
		{
        	x = u[i];
        	ans = 0;
        	ql = L[x];
        	qr = R[x];
        	Query(1, 1, tot);
        	upd = 0;
        	now = Update(1, 1, tot, L[x]);
        	now = 1ll * now * INV(1ll * v[x] * size[x] % P) % P;
        	ans = 1ll * ans * INV(now) % P;
            printf("%d\n",ans);
    	}  
}