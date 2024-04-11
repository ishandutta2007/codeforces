#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ran 555555
int n,a[ran],xx[ran],lx;

int bit[ran];
int lowbit(int x){return x&-x;}
int query(int x){
	int res = 0;
	while(x){
		res = max(res, bit[x]);
		x -= lowbit(x);
	}
	return res;
}
void upd(int x,int y){
	while(x <= lx){
		bit[x] = max(bit[x], y);
		x += lowbit(x);
	}
}

int q[ran],lq;

int rt[ran];
struct Node{
	int lc, rc, val;
} c[ran * 30];
int Z;
void build(int&pnt,int s,int e){
	pnt = ++Z;
	c[pnt].val = 0;
	if(s == e)return;
	int m=(s+e)/2;
	build(c[pnt].lc, s, m);
	build(c[pnt].rc, m+1, e);
}
int query2(int pnt, int s, int e,int x){
	if(e <= x)return c[pnt].val;
	int m = (s + e) / 2;
	if(x <= m)return query2(c[pnt].lc, s, m, x);else
		return max(query2(c[pnt].rc, m+1, e, x), c[c[pnt].lc].val);
}
void upd2(int&pnt,int s,int e,int x,int y){
	int cur = ++Z;
	c[cur] = c[pnt];
	pnt = cur;
	c[pnt].val = max(c[pnt].val, y);
	if(s == e)return;
	int m = (s + e) / 2;
	if(x <= m)upd2(c[pnt].lc, s, m, x, y);else
		upd2(c[pnt].rc, m+1, e, x, y);
}


int main(){
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
			xx[i] = a[i];
		}
		sort(xx,xx+n);
		lx=unique(xx,xx+n)-xx;
		for(int i=0; i<n; i++)
			a[i]=lower_bound(xx,xx+lx,a[i])-xx+1;

		memset(bit,0,sizeof(int)*(lx+1));
		lq = 0;
		Z = 0;
		build(rt[0], 1, lx);
		int res = 0;
		for(int i=0; i<n; i++){
			int cur = query(a[i]) + 1;

			while(lq > 0 && a[q[lq-1]] <= a[i])lq--;
			if(lq > 0){
				cur = max(cur, query2(rt[q[lq-1]-1], 1, lx, a[i]) + 2);
			}
			q[lq++] = i;

			res = max(res, cur);
			upd(a[i], cur);
			rt[i] = rt[i-1];
			upd2(rt[i], 1, lx, a[i], cur);
		}
		printf("%d\n",res);
	}
	return 0;
}