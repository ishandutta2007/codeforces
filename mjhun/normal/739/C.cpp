#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define S 548
using namespace std;
typedef long long ll;

struct node {
	int h,h0,h1,s0,s1;
	ll z;
};

int a[300005];
ll w[300005];
int n,m;
node st[1<<20];

inline void merge(node *r, node *x, node *y, int s, int m, int e, ll z){
	ll a0=a[m-1]+z+x->z;
	ll a1=a[m]+z+x->z+w[m];
	if(x->s0==m-s&&a0>a1)r->s0=x->s0+y->s0;
	else r->s0=x->s0;
	if(y->s1==e-m&&a0<a1)r->s1=x->s1+y->s1;
	else r->s1=y->s1;
	if(x->s1==m-s){
		assert(x->h0==m-s);
		if(a0<a1)r->h0=x->h0+y->h0;
		else if(a0>a1)r->h0=x->h0+y->s0;
		else r->h0=x->h0;
	}
	else if(x->h0==m-s){
		if(a0>a1)r->h0=x->h0+y->s0;
		else r->h0=x->h0;
	}
	else r->h0=x->h0;
	if(y->s0==e-m){
		assert(y->h1==e-m);
		if(a0>a1)r->h1=x->h1+y->h1;
		else if(a0<a1)r->h1=x->s1+y->h1;
		else r->h1=y->h1;
	}
	else if(y->h1==e-m){
		if(a0<a1)r->h1=x->s1+y->h1;
		else r->h1=y->h1;
	}
	else r->h1=y->h1;
	r->h=max(x->h,y->h);
	if(a0<a1)r->h=max(r->h,x->s1+y->h0);
	else if(a0>a1)r->h=max(r->h,x->h1+y->s0);
}

void st_init(int k, int s, int e){
	if(s+1==e){
		st[k].h=st[k].h0=st[k].h1=st[k].s0=st[k].s1=1;
		st[k].z=0;
	}
	else {
		int m=(s+e)/2;
		st_init(2*k,s,m);
		st_init(2*k+1,m,e);
		merge(&st[k],&st[2*k],&st[2*k+1],s,m,e,0);
	}
}

void st_upd(int k, int s, int e, int a, int b, ll z){
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b)return;
	int m=(s+e)/2;
	st_upd(2*k,s,m,a,b,z);
	st_upd(2*k+1,m,e,a,b,z+st[2*k].z);
	merge(&st[k],&st[2*k],&st[2*k+1],s,m,e,z);
}

void updz(int k, int s, int e, int p, int v){
	st[k].z+=v;
	if(s+1==e)return;
	int m=(s+e)/2;
	if(p<m)updz(2*k,s,m,p,v);
	else updz(2*k+1,m,e,p,v);
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	st_init(1,0,n);
	scanf("%d",&m);
	while(m--){
		int l,r,d;
		scanf("%d%d%d",&l,&r,&d);l--;
		w[l]+=d;
		w[r]-=d;
		updz(1,0,n,l,d);
		if(r<n)updz(1,0,n,r,-d);
		st_upd(1,0,n,l,r,0);
		printf("%d\n",st[1].h);
	}
	return 0;
}