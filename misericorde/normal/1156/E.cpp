#include <bits/stdc++.h>
#define maxn 200005
int n,arr[maxn],vis[maxn],cnt=0;

int gmax(int a,int b) {
	if (arr[a]<arr[b]) return b;
	return a;
}

struct segmentTree {
	int left[maxn<<2],right[maxn<<2],max[maxn<<2];
	void build(int l,int r,int rt) {
		left[rt]=l;right[rt]=r;
		if (l==r) {
			max[rt]=l;return;
		} build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		max[rt]=gmax(max[rt<<1],max[rt<<1|1]);
	} int query(int l,int r,int rt) {
		if (left[rt]>r||right[rt]<l) return 0;
		if (l<=left[rt]&&right[rt]<=r) return max[rt];
		return gmax(query(l,r,rt<<1),query(l,r,rt<<1|1));
	}
}sgt;

void solve(int l,int r) {
	if (l>=r) return;
	int p=sgt.query(l,r,1);
	int mid=(l+r)>>1;
	if (p<=mid) {
		for (int i=l;i<p;++i) {
			int p2=vis[arr[p]-arr[i]];
			if (p<p2&&p2<=r) cnt++;
		}
	} else {
		for (int i=p+1;i<=r;++i) {
			int p2=vis[arr[p]-arr[i]];
			if (l<=p2&&p2<p) cnt++;
		}
	} solve(l,p-1); solve(p+1,r);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {scanf("%d",&arr[i]);vis[arr[i]]=i;}
	sgt.build(1,n,1);
	solve(1,n);
	printf("%d",cnt);
	return 0;
}