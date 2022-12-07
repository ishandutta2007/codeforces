#include <bits/stdc++.h>
#define N 300010
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m;
int a[N],b[N],use[N],cnt[N << 1];
int tot,C[N],C_val[N];
long long ans,tmp;
 
struct Node
{
    int x,id,id2;
}t[N << 1];
inline bool cmp(const Node &a,const Node &b)
{
    if(a.x != b.x)return a.x < b.x;
    if(a.id2 != b.id2)return a.id2 < b.id2;
    return a.id < b.id;
}
 
int main()
{
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++)
	{
		a[i] = read();
		b[i] = read();
		a[i] <<= 1;
		b[i] <<= 1;
		if(b[i] - a[i] < a[i]) t[i].x = t[i + n].x = b[i] >> 1, t[i].id2 = i << 1, t[i + n].id2 = i << 1 | 1;
		else t[i].x = a[i], t[i + n].x = b[i] - a[i];
		t[i].id = i;
		t[i + n].id = i + n;
	}

    sort(t + 1, t + n + n + 1, cmp);
    for(int i = 1; i <= m; i ++) 
    	ans += t[i].x, cnt[t[i].id] ++;
    if(t[m].id <= n && !cnt[t[m].id + n] && t[m].x!= a[t[m].id])
    {
        tmp = ans - t[m].x;
        ans = ans - t[m].x + a[t[m].id];
        cnt[t[m].id] --;
        tot = 1;
        C[tot] = t[m].id;
        C_val[tot] = 1;
        for(int i = 1; i <= n; i ++)
        	if(i != t[m].id)
        	{
	            if(!cnt[i])
	                if(a[i] + tmp < ans)
	                {
	                    tot = 0;
	                    C[++ tot] = i;
	                    C_val[tot] = 1;
	                    ans = a[i] + tmp;
	                }
	            if(cnt[i] && !cnt[i + n])
	            {
	                if(tmp + b[i] - a[i] < ans)
	                {
	                    tot = 0;
	                    C[++ tot] = i + n;
	                    C_val[tot] = 1;
	                    ans = tmp + b[i] - a[i];
	                }
	                if(tmp - a[i] + b[t[m].id] < ans)
	                {
	                    tot = 0;
	                    C[++ tot] = i;
	                    C_val[tot] = -1;
	                    C[++ tot] = t[m].id;
	                    C_val[tot] = 1;
	                    C[++ tot] = t[m].id + n;
	                    C_val[tot] = 1;
	                    ans = tmp - a[i] + b[t[m].id];
	                }
	            }
	            if(cnt[i] && cnt[i + n])
	                if(tmp - b[i] + a[i] + b[t[m].id] < ans)
	                {
	                    tot = 0;
	                    C[++ tot] = i + n;
	                    C_val[tot] = -1;
	                    C[++ tot] = t[m].id;
	                    C_val[tot] = 1;
	                    C[++ tot] = t[m].id + n;
	                    C_val[tot] = 1;
	                    ans = tmp - b[i] + a[i] + b[t[m].id];
	                }
        	}
        for(; tot; tot --)
        	cnt[C[tot]] += C_val[tot];
    }
    printf("%I64d\n", ans >> 1);
    for(int i = 1; i <= n; i ++)
    	printf("%d",cnt[i] + cnt[i + n]);
    printf("\n");
    return 0;
}