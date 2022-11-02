# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;

const int MAXN = 300010;
const int SIZE = 1000002;
struct info{int l, r, b;} a[MAXN * 3];
bool operator<(const info& a,const info& b) 
{return a.r<b.r || a.r==b.r && a.b<b.b; }

/* the tree array*/
int s[SIZE], N, res;
void add(int x) {for(x; x<=N; x+=x&(-x)) s[x]++;}
int sum(int x) {
	for(res=0; x>0; x-=x&(-x)) res+=s[x];
	return res;
}

int ans[MAXN];

int main() {
	int n, m, t; scanf("%d%d",&n,&m); t=n;
	for(int i=0; i<n; i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1; i<=m; i++) {
		int size, x=0, w; scanf("%d", &size);
		while(size--) {
			scanf("%d", &w);
			if(x+1<w) a[t].l=x+1,a[t].r=w-1,a[t++].b=i;
			x=w;
		}
		a[t].l=x+1,a[t].r=SIZE,a[t++].b=i;
	}
	
	//for(int i=0; i<t; i++) printf("[%d,%d]{%d}\n",a[i].l,a[i].r,a[i].b);
	sort(a, a+t);
	for(int i=0; i<t; i++) N = max(N, a[i].l);
	//printf("MAXN = %d\n", N);
	int tot = 0;
	for(int i=0; i<t; i++)
		if(a[i].b) ans[a[i].b]+= tot - sum(a[i].l-1);
		else add(a[i].l), tot++;
	for(int i=1; i<=m; i++)	printf("%d\n",tot - ans[i]);
	return 0;
}