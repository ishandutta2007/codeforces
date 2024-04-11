#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef char byte;

struct node {
	node *l,*r;
	byte f1,fg;
}pool[20100000],*cur=pool;

struct monster {
	int a,offset;
	node *h;
	int dead;
}ms[2510000];

int n,c,k,ty,d;

node* build(int l,int r) {
	node *p=cur++;
	if (l==r) {
		p->f1=(l!=0);
	} else {
		int md=(l+r)>>1;
		p->l=build(l,md);
		p->r=build(md+1,r);
		p->f1=p->l->f1|p->r->f1;
	}
	return p;
}

node *setf(node *p,byte v) {
	node *q=cur++; *q=*p;
	q->fg=v;
	if (v==1) q->f1=1; else q->f1=0;
	return q;
}
node* push(node* p) {
	node *q=cur++; *q=*p;
	if (p->fg==0) {
		return q;
	} else {
		q->l=setf(p->l,p->fg);
		q->r=setf(p->r,p->fg);
		q->fg=0;
		return q;
	}
}

int findz(node *p,int l,int r,int tl,int tr,byte fg) {
	if (fg==1) return min(r,tr);
	if (fg==-1) return -1;
	if (p->f1==0) return -1;
	if (tl==l&&tr==r) {
		if (l==r) return l;
		int md=(l+r)>>1;
		int z=findz(p->r,md+1,r,md+1,tr,p->fg);
		if (z!=-1) return z;
		return findz(p->l,l,md,tl,md,p->fg);
	} else {
		int md=(l+r)>>1;
		if (tr<=md) return findz(p->l,l,md,tl,tr,p->fg);
		else if (tl>md) return findz(p->r,md+1,r,tl,tr,p->fg);
		else {
			int z=findz(p->r,md+1,r,md+1,tr,p->fg);
			if (z!=-1) return z;
			return findz(p->l,l,md,tl,md,p->fg);
		}
	}
}


node *modify(node *p,int l,int r,int tl,int tr,byte v) {
	if (tl==l&&tr==r) {
		node *q=setf(p,v);
		return q;
	} else {
		node *q=push(p);
		int md=(l+r)>>1;
		if (tr<=md) q->l=modify(q->l,l,md,tl,tr,v);
		else if (tl>md) q->r=modify(q->r,md+1,r,tl,tr,v);
		else q->l=modify(q->l,l,md,tl,md,v),q->r=modify(q->r,md+1,r,md+1,tr,v);
		q->f1=q->l->f1|q->r->f1;
		return q;
	}
}

void attack(int id,int a,int mt) {
	if (ms[id].offset<=a) {
		ms[id].dead=mt;
		return;
	}
	a=ms[id].offset-a;
	int pos=findz(ms[id].h,0,n,0,a,0);
	if (pos==-1) {
		ms[id].dead=mt;
		return;
	}
	ms[id].h=modify(ms[id].h,0,n,pos,pos,-1);
	if (pos<a) ms[id].h=modify(ms[id].h,0,n,pos+1,a,1);
}

int main() {
	scanf("%d",&n);
	node *rt=build(0,n);
	rep(i,1,n+1) {
		scanf("%d",&ty);
		if (ty==1) {
			k++;
			ms[k].h=rt;
			ms[k].dead=-1;
		} else if (ty==2) {
			scanf("%d",&c);
			if (ms[c].dead!=-1) continue;
			ms[c].a++;
		} else if (ty==3) {
			scanf("%d",&c);
			if (ms[c].dead!=-1) continue;
			ms[c].offset++;
		} else if (ty==4) {
			k++;
			scanf("%d",&c);
			ms[k]=ms[c];
			if (ms[c].dead!=-1) ms[k].dead=i;
		} else {
			scanf("%d%d",&c,&d);
			if (ms[c].dead!=-1||ms[d].dead!=-1) continue;
			attack(c,ms[d].a,i);
			attack(d,ms[c].a,i);
		}
	}
	printf("%d\n",k);
	rep(i,1,k+1) printf("%d%c",ms[i].dead," \n"[i==k]);
}