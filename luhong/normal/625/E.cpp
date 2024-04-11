#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MN 101000

typedef std::pair<int, int> P;
typedef long long ll;

int n, m, p[MN], id[MN];
std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
int nxt[MN], lst[MN];
bool used[MN];
int t[MN], a[MN]; ll d[MN]; 
int A = 1, B = 0;

bool cmp(int a, int b) {return p[a] < p[b];}

void calc(int i)
{
	d[i] = 1ll * (A - t[i] - (i > B)) * a[i] + d[i];
	t[i] = A - (i > B);
}

int calc2(int i, int j)
{
	if(i == j) return 2e9;
	calc(i); calc(j);
	ll x = (p[j] - p[i] + m) % m - d[i] + d[j];
	int w = 0;
	if(i < j)
	{
		if(j <= B) w = 1, x -= a[i];
		if(i > B) x -= a[i];
	}
	else
	{
		if(j <= B && i > B) x -= a[i];
		if(j > B) w = -1;
	}
	if(x <= 0) return A + w;
	if(a[j] >= a[i]) return (int)2e9;
	return A + x / (a[i] - a[j]) + (x % (a[i] - a[j]) > 0) + w;
} 

void del(int i)
{
	nxt[lst[i]] = nxt[i];
	lst[nxt[i]] = lst[i];
	used[i] = 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)	scanf("%d%d", &p[i], &a[i]), id[i] = i;
	std::sort(id + 1, id + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		lst[id[i]] = id[i == 1 ? n : i - 1], nxt[id[i]] = id[i == n ? 1 : i + 1]; 
	for(int i = 1; i <= n; i++)
	{
		int T = calc2(i, nxt[i]); 
		if(T < (int)2e9) pq.push(P(T, i)); 
	}
	while(!pq.empty())
	{
		P p = pq.top(); pq.pop(); int i = p.second;
		if(used[i] || used[nxt[i]] || calc2(i, nxt[i]) != p.first) continue;
		A = p.first; B = i; calc(i); a[i]--; 
		del(nxt[i]);
		int T = calc2(i, nxt[i]); 
		if(T < (int)2e9) pq.push(P(T, i)); 
		T = calc2(lst[i], i);
		if(T < (int)2e9) pq.push(P(T, lst[i])); 
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) if(!used[i]) tot++;
	printf("%d\n", tot);
	for(int i = 1; i <= n; i++) if(!used[i]) printf("%d ", i);
}