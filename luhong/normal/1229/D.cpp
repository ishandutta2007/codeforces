#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#define MN 201000
#define MK 6

int p[MN][MK], ID[MN];
int n, k;
int wz[120];
int fa[120], siz[120];
int to[120][120];
std::set<int> st;

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int id(int *a)	
{
	bool used[6]; memset(used, 0, sizeof(used));
	int ans = 0;
	int w = 1; for(int i = 1; i <= k; i++) w = 1ll * i * w;
	for(int i = 1; i <= k; i++)
	{
		int cnt = 0; w /= (k - i + 1);
		for(int j = 1; j < a[i]; j++)
			if(!used[j]) cnt++;
		used[a[i]] = 1;
		ans = ans + cnt * w;
	}
	return ans;
}

void rid(int ans, int *a)
{
	bool used[6]; memset(used, 0, sizeof(used));
	int w = 1; for(int i = 1; i <= k; i++) w = 1ll * i * w;
	for(int i = 1; i <= k; i++)
	{
		w /= (k - i + 1); int cnt = ans / w + 1; ans %= w; 
		int j;
		for(j = 1; cnt; j++)
			if(!used[j]) cnt--; 
		used[j - 1] = 1;
		a[i] = j - 1;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++) scanf("%d", &p[i][j]);
		ID[i] = id(p[i]);
	}
	
	int w = 1; for(int i = 1; i <= k; i++) w *= i;
	for(int i = 0; i < w; i++)
		for(int j = 0; j < w; j++)
		{
			int b[6], c[6];
			rid(i, b); rid(j, c);
			for(int o = 1; o <= k; o++)
				b[o] = c[b[o]];
			to[i][j] = id(b);
		}
	
	long long ans = 0;
	for(int l = n; l >= 1; l--)
	{
		if(!wz[ID[l]]) wz[ID[l]] = l;
		else st.erase(st.lower_bound(wz[ID[l]])), wz[ID[l]] = l;
		st.insert(l);
		for(int j = 0; j < w; j++) fa[j] = j, siz[j] = 1;
		for(auto it = st.begin(); it != st.end(); ++it)
		{
			int v = ID[*it];
			if(Find(0) != Find(v)) 
				for(int u = 0; u < w; u++)
				{
					int U = Find(to[u][v]), V = Find(u);
					if(U != V) {fa[U] = V; siz[V] += siz[U];}
					if(siz[Find(0)] == w) break;
				}
			auto it2 = it; ++it2;
			if(siz[Find(0)] == w)
			{
				ans = ans + 1ll * (n + 1 - *it) * siz[Find(0)];
				break;
			}
			ans = ans + 1ll * ((it2 == st.end() ? n + 1 : *it2) - *it) * siz[Find(0)];
		}
	}
	printf("%lld\n", ans);
}