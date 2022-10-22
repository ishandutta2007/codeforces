#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
ll read();
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define pct(x) __builtin_popcountll(x)

const int N=1e6+5;
int n,k;
ll a[N],ans,now;
struct SMT {
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
	int seg[N<<2],tag[N<<2],clr[N<<2];
	void puttag(int k,int l,int r,int v) {
		tag[k]+=v; seg[k]+=(r-l+1)*v;
	}
	void clear(int k) {clr[k]=1; seg[k]=tag[k]=0;}
	void pushdown(int k,int l,int r,int mid) {
		if(clr[k]) clear(lc),clear(rc),clr[k]=0;
		if(tag[k]) puttag(left,tag[k]),puttag(right,tag[k]),tag[k]=0;
	}
	void change(int k,int l,int r,int x,int y,int v) {
		if(x<=l&&r<=y) return puttag(k,l,r,v);
		int mid=l+r>>1; pushdown(k,l,r,mid);
		if(x<=mid) change(left,x,y,v);
		if(y>mid) change(right,x,y,v);
		seg[k]=seg[lc]+seg[rc];
	}
	int query(int k,int l,int r,int x,int y) {
		if(x<=l&&r<=y) return seg[k];
		int mid=l+r>>1,res=0; pushdown(k,l,r,mid);
		if(x<=mid) res=query(left,x,y);
		if(y>mid) res+=query(right,x,y);
		return res;
	}
} T[2];

int s1[N],s2[N],t1,t2;
struct Event {
	int l,r,k,tim,op;
} q1[N<<1],q2[N<<1];
int m1,m2;
bool cmp(const Event &a,const Event &b) {
	if(a.k^b.k) return a.k<b.k;
	if(a.tim^b.tim) return a.tim<b.tim;
	return a.op<b.op;
}
void work(int l,int r,int cl,int job) {
	T[cl].change(1,1,n,l,r,job);
	now+=T[cl^1].query(1,1,n,l,r)*job;
}
int main() {
	n=read();
	fr(i,1,n) a[i]=read();
	fr(i,1,n) {
		while(t1&&a[s1[t1]]<=a[i]) {
			k=pct(a[s1[t1]]);
			q1[++m1]=(Event){s1[t1-1]+1,s1[t1],k,i,-1};
			--t1;
		}
		s1[++t1]=i; k=pct(a[i]);
		q1[++m1]=(Event){s1[t1-1]+1,s1[t1],k,i,1};

		while(t2&&a[s2[t2]]>=a[i]) {
			k=pct(a[s2[t2]]);
			q2[++m2]=(Event){s2[t2-1]+1,s2[t2],k,i,-1};
			--t2;
		}
		s2[++t2]=i; k=pct(a[i]);
		q2[++m2]=(Event){s2[t2-1]+1,s2[t2],k,i,1};
	}
	sort(q1+1,q1+m1+1,cmp);
	sort(q2+1,q2+m2+1,cmp);
	int r1=0,r2=0,l1,l2;
	for(k=0;k<60;++k) {
		l1=r1+1,l2=r2+1;
		while(r1<m1&&q1[r1+1].k==k) ++r1;
		while(r2<m2&&q2[r2+1].k==k) ++r2;

		int lst=1;
		for(int pt1=l1,pt2=l2;pt1<=r1||pt2<=r2;) {
			if(pt2>r2||(pt1<=r1&&q1[pt1].tim<=q2[pt2].tim)) {
				//cout<< q1[pt1].op << " 1 " << q1[pt1].tim<< ' ' << lst<< endl;
				//cout << q1[pt1].l << ' ' << q1[pt1].r << endl;
				ans+=now*(q1[pt1].tim-lst);
				work(q1[pt1].l,q1[pt1].r,0,q1[pt1].op);
				lst=q1[pt1++].tim;
			} else {
				//cout<< q2[pt2].op << " 2 " << q2[pt2].tim<< ' ' << lst<< endl;
				ans+=now*(q2[pt2].tim-lst);
				work(q2[pt2].l,q2[pt2].r,1,q2[pt2].op);
				lst=q2[pt2++].tim;
			}
			//cout << now<< '!' << ans << endl;
		}
		ans+=now*(n+1-lst);
		T[0].clear(1); T[1].clear(1);
		now=0;
		//cout << ans << endl; if(k) exit(0);
	}
	cout<<ans<<endl;
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline ll read() {
	static ll x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}