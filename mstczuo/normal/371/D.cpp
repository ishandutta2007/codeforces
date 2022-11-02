# include <iostream>
# include <cstdio>
using namespace std;

const int N = 200010;
int a[N], v[N], f[N], n, m, t;
int find(int x){ 
	return f[x]==x ? x : 
	(f[x]=find(f[x]));
}

void add() {

	int x, val;
	scanf("%d%d",&x, &val);
	x = find(x);

	while ( val > 0 && x <= n ) {
		if(v[x] + val < a[x]) {v[x] += val; break;}
		val -= (a[x] - v[x]);
		v[x] = a[x];
		f[x] = find(x+1);
		x = f[x];
	}
}

int main() {
	scanf("%d", &n); f[n+1] = n+1;
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]), f[i]=i;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &t);
		if (t == 1) add();
		else scanf("%d",&t), printf("%d\n",v[t]);
	}
	return 0;
}