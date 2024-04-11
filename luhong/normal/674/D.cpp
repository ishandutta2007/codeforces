#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#define MN 101000

typedef long long ll;

int n, q;
ll t[MN];
int f[MN], d[MN];
ll s[MN];
std::multiset<ll> st;
std::multiset<ll> son[MN];
bool used[MN];

void update(int x, int ty) {s[f[x]] += ty * (t[x] / (d[x] + 2));}
ll calc3(int x) {return t[x] / (d[x] + 2);}
ll calc2(int x) {return s[x] + (t[x] - (d[x] + 1) * (t[x] / (d[x] + 2)));}
ll calc(int x) {return s[x] + (t[x] - (d[x] + 1) * (t[x] / (d[x] + 2))) + (t[f[x]] / (d[f[x]] + 2));}

void del2(int x)
{
	if(son[x].empty()) return;
	st.erase(st.find(*son[x].begin() + calc3(x)));
	st.erase(st.find(*son[x].rbegin() + calc3(x)));
}

void del(int x)
{
	son[f[x]].erase(son[f[x]].find(calc2(x)));
}

void add2(int x)
{
	if(son[x].empty()) return;
	st.insert(*son[x].begin() + calc3(x));
	st.insert(*son[x].rbegin() + calc3(x));
}

void add(int x)
{
	son[f[x]].insert(calc2(x));
}

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%lld", &t[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &f[i]), d[f[i]]++;
	for(int i = 1; i <= n; i++) update(i, 1);
	for(int i = 1; i <= n; i++) son[f[i]].insert(calc2(i));
	for(int i = 1; i <= n; i++) add2(i);
	
	while(q--)
	{
		int opt, i, j; scanf("%d", &opt);
		if(opt == 1)
		{
			scanf("%d%d", &i, &j);
			int k = f[i];
			
			if(!used[j]) del2(j), used[j] = 1;
			if(!used[k]) del2(k), used[k] = 1;
			if(!used[f[j]]) del2(f[j]), used[f[j]] = 1;
			if(!used[f[k]]) del2(f[k]), used[f[k]] = 1;
			if(!used[f[f[j]]]) del2(f[f[j]]), used[f[f[j]]] = 1;
			if(!used[f[f[k]]]) del2(f[f[k]]), used[f[f[k]]] = 1;
			used[j] = used[k] = used[f[j]] = used[f[k]] = used[f[f[j]]] = used[f[f[k]]] = 0;
			
			if(!used[i]) del(i), used[i] = 1;
			if(!used[j]) del(j), used[j] = 1;
			if(!used[k]) del(k), used[k] = 1;
			if(!used[f[j]]) del(f[j]), used[f[j]] = 1;
			if(!used[f[k]]) del(f[k]), used[f[k]] = 1;
			used[i] = used[j] = used[k] = used[f[j]] = used[f[k]] = 0;
			
			update(i, -1); update(k, -1); update(j, -1);
			f[i] = j; d[k]--; d[j]++;
			update(i, 1); update(k, 1); update(j, 1);
			
			if(!used[i]) add(i), used[i] = 1;
			if(!used[j]) add(j), used[j] = 1;
			if(!used[k]) add(k), used[k] = 1;
			if(!used[f[j]]) add(f[j]), used[f[j]] = 1;
			if(!used[f[k]]) add(f[k]), used[f[k]] = 1;
			used[i] = used[j] = used[k] = used[f[j]] = used[f[k]] = 0;
			
			if(!used[j]) add2(j), used[j] = 1;
			if(!used[k]) add2(k), used[k] = 1;
			if(!used[f[j]]) add2(f[j]), used[f[j]] = 1;
			if(!used[f[k]]) add2(f[k]), used[f[k]] = 1;
			if(!used[f[f[j]]]) add2(f[f[j]]), used[f[f[j]]] = 1;
			if(!used[f[f[k]]]) add2(f[f[k]]), used[f[f[k]]] = 1;
			used[j] = used[k] = used[f[j]] = used[f[k]] = used[f[f[j]]] = used[f[f[k]]] = 0;
		}
		if(opt == 2)
		{
			scanf("%d", &i);
			printf("%lld\n", calc(i));
		}
		if(opt == 3) printf("%lld %lld\n", *st.begin(), *st.rbegin());
		
	}
}