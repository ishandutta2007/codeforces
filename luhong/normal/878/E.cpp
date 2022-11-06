#include <cstdio>
#include <iostream>
#include <algorithm>
#define MN 501000
#define mod 1000000007

typedef long long ll;
 
int a[MN], sum[MN];
int mi[MN], inv[MN];
int fa[MN], L[MN], R[MN];
ll val[MN], Ans[MN], s[MN]; bool ok[MN];
struct xxx {
	int l, r, id;
}q[MN];

ll S(int l, int r) {return 1ll * (sum[r] - sum[l - 1] + mod) * inv[l - 1] % mod;}

bool cmp(xxx a, xxx b) {return a.r < b.r;}

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int main()
{
    int n, Q; scanf("%d%d", &n, &Q);
     
    mi[0] = inv[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        mi[i] = mi[i - 1] * 2ll % mod;
        inv[i] = inv[i - 1] * 500000004ll % mod;
    }
	
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + 1ll * (a[i] + mod) * mi[i]) % mod;
    for(int i = 1; i <= Q; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    
    std::sort(q + 1, q + Q + 1, cmp);
    
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
    	fa[i] = i; L[i] = R[i] = i; val[i] = 2 * a[i]; s[i] = s[Find(i - 1)] + val[i]; ok[i] = 0;
    	int rt = Find(i);
    	while(L[rt] > 1 && (val[rt] > 0 || ok[rt]))
    	{
    		int k = Find(L[rt] - 1);
    		if(ok[rt] || R[k] - L[k] + 1 >= 60 || 1.0 * (1ll << (R[k] - L[k] + 1)) * val[rt] + val[k] >= 2000000000)
    		{
    			ok[k] = 1;
    			val[k] += 1ll * mi[R[k] - L[k] + 1] * val[rt];
    			val[k] = (val[k] % mod + mod) % mod; 
			}
			else
			{
    			val[k] += 1ll * mi[R[k] - L[k] + 1] * val[rt];
			}
			fa[rt] = k; R[k] = R[rt]; 
			s[k] = s[Find(L[k] - 1)] + val[k];
			rt = Find(i);
		}
		while(j <= Q && q[j].r == i)
		{
			ll ans = S(q[j].l + 1, R[Find(q[j].l)]) + (s[Find(i)] - s[Find(q[j].l)]) + a[q[j].l];
			Ans[q[j].id] = (ans % mod + mod) % mod; j++;
		}
	}
	for(int i = 1; i <= Q; i++) printf("%lld\n", Ans[i]);
}