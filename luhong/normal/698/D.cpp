#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define MK 7
#define MN 1010

typedef std::vector<int> V;
typedef long long ll;

std::map<V, bool> f[1 << MK];
V b[MK][MN];
int k, n; 

struct xxx {
	ll x, y;
	xxx(){}
	xxx(ll a, ll b) {x = a; y = b;}
}p[MN], q[MN];

xxx operator - (xxx a, xxx b) {return xxx(a.x - b.x, a.y - b.y);}
ll operator / (xxx a, xxx b) {return a.x * b.y - a.y * b.x;}

bool solve(V v, int S)
{
	if(f[S].find(v) != f[S].end()) return f[S][v];
	if(v.size() == 0) return 1; 
	f[S][v] = 0;
	int siz = 0;
	for(int i = 0; i < k; i++) if((S >> i) & 1) siz++;
	
	for(int i = 0; i < k; i++)
	{
		if((S >> i) & 1)
		{
			for(int j = 0; j < v.size(); j++)
			{
				if(b[i][v[j]].size() <= siz)
				{
					V t = v;
					for(int o = 0; o < b[i][v[j]].size(); o++)
						t.push_back(b[i][v[j]][o]);
					std::sort(t.begin(), t.end()); auto it = std::unique(t.begin(), t.end()); t.erase(it, t.end());
					for(int o = 0; o < t.size(); o++) if(t[o] == v[j]) {t.erase(t.begin() + o); break;}
					if(t.size() <= siz - 1 && solve(t, S ^ (1 << i))) return f[S][v] = 1;
				}
			}
		}
	}
	return f[S][v];
}

int main()
{
	scanf("%d%d", &k, &n);
	for(int i = 0; i < k; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &q[i].x, &q[i].y);
	
	for(int i = 0; i < k; i++)
		for(int j = 1; j <= n; j++)
			for(int o = 1; o <= n; o++)
				if((q[o] - p[i]) / (q[j] - q[o]) == 0 && (q[o] - p[i]).x * (q[j] - q[o]).x >= 0 && (q[o] - p[i]).y * (q[j] - q[o]).y >= 0)
					b[i][j].push_back(o);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		V v; v.clear(); v.push_back(i);
		int ok = 0;
		for(int j = 1; j < (1 << k); j++)
		{
			if(solve(v, j)) {ok = 1; break;}
		}
		ans += ok;
	}
	printf("%d\n", ans);
}