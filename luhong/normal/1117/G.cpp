#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>
#define MN 1010000

struct xxx{
	int x, id, t;
}q[2 * MN];

typedef long long ll;
int l[MN], r[MN], a[MN];
int st[MN], top = 0;
int L[MN], R[MN];
ll c[MN], Ans[MN];
int n, Q; 

bool cmp(xxx a, xxx b) {return a.x < b.x;}
void add(int x, ll v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
ll query(int x) {ll ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

int main()
{
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		while(top && a[st[top]] <= a[i]) r[st[top--]] = i - 1;
		l[i] = st[top] + 1; st[++top] = i;
	}
	for(int i = 1; i <= top; i++) r[st[i]] = n;
	for(int i = 1; i <= Q; i++) scanf("%d", &L[i]);
	for(int i = 1; i <= Q; i++) scanf("%d", &R[i]);
	
	int tot = 0;
	for(int i = 1; i <= Q; i++) q[++tot] = xxx{R[i], i, 0};
	for(int i = 1; i <= n; i++) q[++tot] = xxx{r[i], i, 1};
	std::sort(q + 1, q + tot + 1, cmp);
	
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= tot; i++) //Ri >= ri
	{
		int w = q[i].id; 
		if(q[i].t == 1) add(w, r[w]);
		else Ans[w] += query(R[w]) - query(L[w] - 1);
	}
	
	memset(c, 0, sizeof(c));
	for(int i = tot; i >= 1; i--) //Ri <= ri
	{
		int w = q[i].id;
		if(q[i].t == 1) add(w, 1);
		else Ans[w] += (query(R[w]) - query(L[w] - 1)) * R[w];
	}
	
	tot = 0;
	for(int i = 1; i <= Q; i++) q[++tot] = xxx{L[i], i, 0};
	for(int i = 1; i <= n; i++) q[++tot] = xxx{l[i], i, 1};
	std::sort(q + 1, q + tot + 1, cmp);
	
	memset(c, 0, sizeof(c));
	for(int i = tot; i >= 1; i--) //Li <= li
	{
		int w = q[i].id;
		if(q[i].t == 1) add(w, -l[w]);
		else Ans[w] += query(R[w]) - query(L[w] - 1);
	}
	
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= tot; i++) //Li >= li
	{
		int w = q[i].id;
		if(q[i].t == 1) add(w, -1);
		else Ans[w] += (query(R[w]) - query(L[w] - 1)) * L[w];
	}
	
	for(int i = 1; i <= Q; i++) printf("%lld ", Ans[i] + R[i] - L[i] + 1);
}

//ij
//Lj <= i <= Rj 
//min(Rj, ri) - max(Lj, li) + 1