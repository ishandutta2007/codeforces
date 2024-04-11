#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define MN 201000

typedef long long ll;
int n, m, tot = 0, g;
ll ans = 0; 
std::vector<int> a[MN], b[MN];
std::map<int, int> mp;
int T[MN];

struct xxx{
	int w, t, o;
	xxx(){}
	xxx(int a, int b, int c) {w = a; t = b; o = c;}
}d[MN];

bool cmp(xxx a, xxx b) {return a.w == b.w ? (a.t == b.t ? a.o < b.o : a.t > b.t) : a.w < b.w;}

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
void exgcd(int a, int b, int &x, int &y)
{
	if(b == 0) {x = 1; y = 0; return;}
	exgcd(b, a % b, x, y);
	int t = x; x = y; y = t - a / b * y;
}

void solve(int n, int m, std::vector<int> a, std::vector<int> b, int T)
{
	int tot = 0;
	int x, y; exgcd(n, m, x, y); 
	for(int i = 0; i < a.size(); i++) d[++tot] = xxx((1ll * x * a[i] % m + m) % m, a[i], 0);
	for(int i = 0; i < b.size(); i++) d[++tot] = xxx((1ll * x * b[i] % m + m) % m, b[i], 1);
	std::sort(d + 1, d + tot + 1, cmp); 
	d[tot + 1].w = d[1].w + m; 
	for(int i = 1; i <= tot; i++)
		if(d[i + 1].w != d[i].w && (d[i + 1].w != d[i].w + 1 || d[i].o == 0))
			ans = std::max(ans, (1ll * (d[i + 1].w - d[i].w - 1) * n + d[i].t) * g + T);
	
	tot = 0;
	for(int i = 0; i < a.size(); i++) d[++tot] = xxx((1ll * y * a[i] % n + n) % n, a[i], 1);
	for(int i = 0; i < b.size(); i++) d[++tot] = xxx((1ll * y * b[i] % n + n) % n, b[i], 0);
	std::sort(d + 1, d + tot + 1, cmp);
	d[tot + 1].w = d[1].w + n;
	for(int i = 1; i <= tot; i++) 
		if(d[i + 1].w != d[i].w && (d[i + 1].w != d[i].w + 1 || d[i].o == 0))
			ans = std::max(ans, (1ll * (d[i + 1].w - d[i].w - 1) * m + d[i].t) * g + T);
}

int main()
{
	scanf("%d%d", &n, &m);
	g = gcd(n, m);
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		int w;
		scanf("%d", &w);
		if(!mp[w % g]) mp[w % g] = ++tot, T[tot] = w % g;
		a[mp[w % g]].push_back(w / g);
	}
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		int w;
		scanf("%d", &w);
		if(!mp[w % g]) mp[w % g] = ++tot, T[tot] = w % g;
		b[mp[w % g]].push_back(w / g);
	}
	if(tot < g) return 0 * puts("-1");
	for(int i = 1; i <= tot; i++) solve(n / g, m / g, a[i], b[i], T[i]);
	printf("%lld\n", ans);
}