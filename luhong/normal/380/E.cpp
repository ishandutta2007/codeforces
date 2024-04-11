#include <stdio.h>
#include <set>
#include <iostream>
#include <algorithm>
#define MN 301000

int n;
double s1[MN], s2[MN], mi[MN];
int id[MN], a[MN];
int lst[MN], nxt[MN];
std::set<int> st;

bool cmp(int x, int y) {return a[x] > a[y];}

int main()
{
	scanf("%d", &n);
	mi[0] = 1; st.insert(0); st.insert(n + 1);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i, mi[i] = mi[i - 1] * 0.5;
	std::sort(id + 1, id + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		int w = id[i];
		std::set<int>::iterator it, it2;
		it = st.lower_bound(w);
		
		int u = *it; int lstw = w;
		nxt[w] = u; lst[u] = w;
		for(int j = 0; j <= 60; j++)
		{
			s2[w] += (u - lstw) * mi[j]; 
			if(u == n + 1) break;
			lstw = u;
			u = nxt[u];
		}
		
		it--;
		u = *it; lstw = w;
		nxt[u] = w; lst[w] = u;
		for(int j = 0; j <= 60; j++)
		{
			s1[w] += (lstw - u) * mi[j];
			if(!u) break;
			lstw = u;
			u = lst[u];
		}
		
		st.insert(w);
	}
	double ans = 0;
	for(int i = 1; i <= n; i++) ans = ans + s1[i] * s2[i] * a[i] * 0.5;
	printf("%.10lf\n", ans / n / n);
}