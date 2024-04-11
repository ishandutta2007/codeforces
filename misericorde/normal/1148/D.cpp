#include <bits/stdc++.h>
#define maxn 300005
int n,a,b,t1=0,t2=0,ans1[maxn],ans2[maxn],c1=0,c2=0;
struct pair {
	int a,b,id;
}A[maxn],B[maxn];
int cmp1(pair a,pair b) {return a.a>b.a;}
int cmp2(pair a, pair b) {return a.a<b.a;}
int gmax(int a,int b) {
	if (!a)return b;
	if (!b) return a;
	if (A[a].a>A[b].a) return a;
	else return b;
}int gmin(int a,int b) {
	if (!a)return b;
	if (!b) return a;
	if (B[a].a<B[b].a) return a;
	else return b;
}
struct segmentTree {
	int plc[maxn<<2];
	void build1(int l,int r,int rt) {
		if (l==r) {
			plc[rt]=l; return;
		}build1(l,(l+r)>>1,rt<<1);
		build1(((l+r)>>1)+1,r,rt<<1|1);
		plc[rt]=gmax(plc[rt<<1],plc[rt<<1|1]);
	} int query1(int L,int R,int l,int r,int rt) {
		if (l>R||r<L) return 0;
		if (l<=L&&R<=r) return plc[rt];
		return gmax(query1(L,(L+R)>>1,l,r,rt<<1),query1(((L+R)>>1)+1,R,l,r,rt<<1|1));
	} void modify1(int L,int R,int p,int rt) {
		if (L==R) {plc[rt]=0;return;}
		int mid=(L+R)>>1;
		if (p<=mid) modify1(L,mid,p,rt<<1);
		else modify1(mid+1,R,p,rt<<1|1);
		plc[rt]=gmax(plc[rt<<1],plc[rt<<1|1]);
	}
	void build2(int l,int r,int rt) {
		if (l==r) {
			plc[rt]=l; return;
		}build2(l,(l+r)>>1,rt<<1);
		build2(((l+r)>>1)+1,r,rt<<1|1);
		plc[rt]=gmin(plc[rt<<1],plc[rt<<1|1]);
	} int query2(int L,int R,int l,int r,int rt) {
		if (l>R||r<L) return 0;
		if (l<=L&&R<=r) return plc[rt];
		return gmin(query2(L,(L+R)>>1,l,r,rt<<1),query2(((L+R)>>1)+1,R,l,r,rt<<1|1));
	} void modify2(int L,int R,int p,int rt) {
		if (L==R) {plc[rt]=0;return;}
		int mid=(L+R)>>1;
		if (p<=mid) modify2(L,mid,p,rt<<1);
		else modify2(mid+1,R,p,rt<<1|1);
		plc[rt]=gmin(plc[rt<<1],plc[rt<<1|1]);
	}
}sgt1;
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d",&a,&b);
		if (a<b) {A[++t1].a=a;A[t1].b=b;A[t1].id=i;}
		else {B[++t2].a=a;B[t2].b=b;B[t2].id=i;}
	}int now=n*10,p=1,ans=0,tot=0;
	if (t1){
		std::sort(A+1,A+t1+1,cmp1);
		sgt1.build1(1,t1,1);
		
		
		while (p<=t1) {
			while (A[p].a>now&&p<=t1) p++;
			if (p>t1) break;
			int x=sgt1.query1(1,t1,p,t1,1);
			if (x==0) break;
			ans1[++c1]=A[x].id;
			sgt1.modify1(1,t1,x,1);
			tot++; now=A[x].b;
		}ans=tot;tot=0;
	} if (t2) {
		std::sort(B+1,B+t2+1,cmp2);
		//for (int i=1;i<=t2;++i) printf("%d %d\n",B[i].a,B[i].b);
		sgt1.build2(1,t2,1); //printf("!");
		now=0,p=1;
		while (p<=t2) {
			while (B[p].a<now&&p<=t2) p++;
			if (p>t2) break;
			int x=sgt1.query2(1,t2,p,t2,1);
			if (!x) break;
			ans2[++c2]=B[x].id;
			sgt1.modify2(1,t2,x,1);
			tot++; now=B[x].b;
		}
	}
	printf("%d\n",std::max(ans,tot));
	if (ans>tot) {
		for (int i=1;i<=ans;++i) printf("%d ",ans1[i]);
	} else for (int i=1;i<=tot;++i) printf("%d ",ans2[i]);
	return 0;
}