#include<bits/stdc++.h>
#define maxn 100005
#define maxm 100005
#define maxl 20
using namespace std;
struct journey {
	int a,b;
	int l,r;
	int k;
};
typedef journey jrn;
struct node {
	int x,y,cnt;
	node *l, *r;
	node(int xi,int yi,int cnti,node* li,node* ri) {
		x=xi;
		y=yi;
		cnt=cnti;
		l=li;
		r=ri;
	}
};
node* null;
node* rt[maxn];
int n,m;
int p[maxn];
vector<int> a[maxn];
int des[maxn];
int d[maxn];
vector<jrn> q;
int lc[maxn][maxl];
node* insert(node* a, int vl,int l,int r) {
	if(l==r) {
		if(a==NULL) return new node(l,r,1,NULL,NULL);
		else return new node(l,r,a->cnt+1,NULL,NULL);
	}
	else {
		if(a==NULL) {
			int m=(l+r)>>1;
			if(vl>m) return new node(l,r,1,NULL,insert(NULL,vl,m+1,r));
			else return new node(l,r,1,insert(NULL,vl,l,m),NULL);
		}
		else {
			int m=(l+r)>>1;
			if(vl>m) return new node(l,r,1+a->cnt,a->l,insert(a->r,vl,m+1,r));
			else return new node(l,r,1+a->cnt,insert(a->l,vl,l,m),a->r);
		}
	}
}
void dfs(int u) {
	int v;
	int k=0;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i];
		k=1;
		lc[v][0]=u;
		while(k<maxl) {
			lc[v][k]=lc[lc[v][k-1]][k-1];
			k++;
		}
		d[v]=d[u]+1;
		rt[v]=insert(rt[u],des[v],0,m+1);
		dfs(v);
	}
}
int lca(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	int l=1;
	int k=0;
	while(d[u]>d[v]) {
		if((d[u]-d[v])&l) {
			u=lc[u][k];
		}
		l=l<<1;
		k++;
	}
	k=maxl-1;
	while(u!=v) {
		if(lc[u][0]==lc[v][0]) return lc[u][0];
		while(lc[u][k]==lc[v][k]) k--;
		u=lc[u][k];
		v=lc[v][k];
	}
	return u;
}
int query(node* a,int x,int y) {
	if(a==NULL) return 0;
	if(x <= a->x && a->y <= y) return a->cnt;
	int m=(a->x+a->y)>>1;
	int rt=0;
	if(y>m) rt+=query(a->r,x,y);
	if(x<=m) rt+=query(a->l,x,y);
	return rt;
}
int mid(int a,int b) {
	int c=(d[a]+d[b])>>1;
	int k=0;
	int l=1;
	while(d[a]!=c) {
		if((d[a]-c)&l) a=lc[a][k];
		l=l<<1;
		k++;
	}
	return a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
		a[p[i]].push_back(i);
	}
	scanf("%d",&m);
	for(int i=0;i<=n;i++) {
		des[i]=m+1;
		rt[i]=NULL;
	}
	int o,a,b,k,x,y,t,r,s;
	for(int i=1;i<=m;i++) {
		scanf("%d",&o);
		if(o==1) {
			scanf("%d",&t);
			des[t]=i;
		}
		else {
			scanf("%d %d %d %d",&a,&b,&k,&y);
			q.push_back({a,b,y+1,i,k});
		}
	}
	rt[0]=insert(NULL,des[0],0,m+1);
	dfs(0);
	bool no=false;
	for(int i=0;i<q.size();i++) {
		no=false;
		a=q[i].a;
		b=q[i].b;
		o=b;
		x=q[i].l;
		y=q[i].r;
		k=q[i].k;
		if(des[a]<x || des[a]>y) k++; 
		r=lca(a,b);
		s=p[r];
		if(r==a || r==b) {
			if(r==a) {
				t=(d[b]-d[s])-(query(rt[b],x,y)-query(rt[s],x,y));
				a=b;
				b=s;
				if(t<k) no=true;
				else k=t-k+1;
			}
			else {
				t=(d[a]-d[s])-(query(rt[a],x,y)-query(rt[s],x,y));
				b=s;
				if(t<k) no=true;
			}
		}
		else {
			t=(d[a]-d[s])-(query(rt[a],x,y)-query(rt[s],x,y));
			if(t>=k) b=s;
			else {
				a=b;
				b=r;
				k-=t;
				t=(d[a]-d[b])-(query(rt[a],x,y)-query(rt[b],x,y));
				if(t<k) no=true;
				else k=t-k+1;
			}
		}
		//printf("%d %d %d %d %d %d\n",a,b,r,s,t,k);
		if(no) {
			printf("-1\n");
		}
		else {
			while(d[a]-d[b]>1) {
				m=mid(a,b);
				t=(d[a]-d[m])-(query(rt[a],x,y)-query(rt[m],x,y));
				//cout<<m<<" "<<t<<" "<<k<<endl;
				if(t>=k) b=m;
				else {
					a=m;
					k-=t;
				}
			}
			//cout<<a<<endl;
			if(a!=o) printf("%d\n",a);
			else printf("-1\n");
		}
	}
	return 0;
}