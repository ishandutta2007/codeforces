#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
/* Configuration */

#define MAXN 200005
#define MAXM 400005

struct edge {
	int u,v;
}e[MAXM],choose[MAXM];

int n,m,s,t,ds,dt,cnt=0;
int f[MAXN];

inline void init() {
	for (int i=1;i<=n;i++) {
		f[i]=i;
	}
}

int getf(int x) {
	if (f[x]==x) return x;
	return f[x]=getf(f[x]);
}

inline bool merge(int a,int b) {
	int fa=getf(a),fb=getf(b);
	if (fa!=fb) {
		f[fa]=fb;
		return 1;
	}
	else return 0;
}

int sto[MAXN],tto[MAXN];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&e[i].u,&e[i].v);
	}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	init();
	int dds=0,ddt=0;
	for (int i=1;i<=m;i++) {
		if (e[i].u!=s && e[i].v!=s && e[i].u!=t && e[i].v!=t) {
			if (merge(e[i].u,e[i].v)) {
				choose[++cnt]=e[i];
			}
		}
		else {
			if (e[i].v==s || e[i].u==t) swap(e[i].u,e[i].v);
		}
	}
	for (int i=1;i<=m;i++) {
		if (e[i].u==s && e[i].v!=t) {
			sto[getf(e[i].v)]=1;
		}
		else if (e[i].u!=s && e[i].v==t) {
			tto[getf(e[i].u)]=1;
		}
	}
	for (int i=1;i<=m && dds<ds;i++) {
		if (e[i].u==s && e[i].v!=t && !tto[getf(e[i].v)] && merge(e[i].u,e[i].v)) {
			choose[++cnt]=e[i];
			dds++;	
		}
	}
	for (int i=1;i<=m && ddt<dt;i++) {
		if (e[i].u!=s && e[i].v==t && !sto[getf(e[i].u)] && merge(e[i].u,e[i].v)) {
			choose[++cnt]=e[i];
			ddt++;	
		}
	}
	for (int i=1;i<=m && dds<ds;i++) {
		if (e[i].u==s && e[i].v!=t && merge(e[i].u,e[i].v)) {
			choose[++cnt]=e[i];
			dds++;	
		}
	}
	for (int i=1;i<=m && ddt<dt;i++) {
		if (e[i].u!=s && e[i].v==t && merge(e[i].u,e[i].v)) {
			choose[++cnt]=e[i];
			ddt++;	
		}
	}
	for (int i=1;i<=m && dds<ds && ddt<dt;i++) {
		if (e[i].u==s && e[i].v==t) {
			if (merge(e[i].u,e[i].v)) {
				choose[++cnt]=e[i];
				dds++,ddt++;
			}
		}
	}
	if (cnt!=n-1) {
		puts("No");
	}
	else {
		puts("Yes");
		for (int i=1;i<n;i++) {
			printf("%d %d\n",choose[i].u,choose[i].v);
		}
	}

	return 0;
}