#include <bits/stdc++.h>
#define maxn 200005
//lgoj
int n,q,arr[maxn]={0},arr2[maxn],a,b,vis[maxn]={0},tail=0,det[maxn],sum[maxn],rank[maxn];
 
int cmp(int a,int b) {return vis[a]<vis[b];}
 
int gmax(int a,int b) {
	if (arr[a]>arr[b]) return a;
	return b;
}
struct segmentTree {
	int max[maxn<<2];
	void build(int l,int r,int rt) {
		if (l==r) {
			max[rt]=l;return;
		}build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		max[rt]=gmax(max[rt<<1],max[rt<<1|1]);
	} int query(int L,int R,int l,int r,int rt) {
		if (l>R||r<L) return 0;
		if (l<=L&&R<=r) return max[rt];
		return gmax(query(L,(L+R)>>1,l,r,rt<<1),query(((L+R)>>1)+1,R,l,r,rt<<1|1));
	} void modify(int l,int r,int p,int rt) {
		if (l==r) {
			arr[l]=0;return;
		}int mid=(l+r)>>1;
		if (p<=mid) modify(l,mid,p,rt<<1);
		else modify(mid+1,r,p,rt<<1|1);
		max[rt]=gmax(max[rt<<1],max[rt<<1|1]);
	}
}sgt;
 
int main() {
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&n);
		tail=0;
		for (int i=1;i<=n;++i) {
			scanf("%d%d",&a,&b);
			vis[a]++;sum[a]+=b;rank[i]=i;
		}std::sort(rank+1,rank+n+1,cmp);
		for (int i=1;i<=n;++i) {
		//	printf("[%d %d]\n",vis[rank[i]],sum[rank[i]]);
			if (vis[rank[i]]!=0) {arr[++tail]=sum[rank[i]];arr2[tail]=vis[rank[i]];}
			vis[rank[i]]=0;sum[rank[i]]=0;
		}int last=n+1,ans=0;
		//for (int i=1;i<=n;++i) printf("%d ",arr[i]); printf("\n");
	//	for (int i=1;i<=n;++i) printf("%d ",arr2[i]); printf("\n");
		for (int i=tail;i>=1;i--) {
			det[i]=std::max(0,std::min(arr2[i],last-1));
			last=det[i];ans+=det[i];
		}printf("%d ",ans);ans=0;sgt.build(1,n,1);
		
		for (int i=tail;i>=1;i--) {
			int lb=std::lower_bound(arr2+1,arr2+tail+1,det[i])-(arr2+1)+1;
			int p=sgt.query(1,n,lb,n,1);
		//	printf(">%d %d %d\n",lb,p,det[i]);
			ans+=std::min(det[i],arr[p]);
			sgt.modify(1,n,p,1);
		}printf("%d\n",ans);
	}
			
	return 0;
}