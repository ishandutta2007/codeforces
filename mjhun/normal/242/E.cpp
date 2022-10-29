#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

void merge(int *s0, int *s1, int *t){
	int tt[20];
	fore(i,0,20)tt[i]=s0[i]+s1[i];
	fore(i,0,20)t[i]=tt[i];
}

int st[1<<19][20];
int a[100005];
int lazy[1<<19];
int n;

void prop(int k, int s, int e){
	fore(i,0,20)if(lazy[k]&(1<<i))st[k][i]=e-s-st[k][i];
	if(s+1<e){
		lazy[2*k]^=lazy[k];
		lazy[2*k+1]^=lazy[k];
	}
	lazy[k]=0;
}

void st_init(int k, int s, int e){
	if(s+1==e){
		fore(i,0,20)if(a[s]&(1<<i))st[k][i]++;
		return;
	}
	int m=(s+e)/2;
	st_init(2*k,s,m);
	st_init(2*k+1,m,e);
	merge(st[2*k],st[2*k+1],st[k]);
}

void st_upd(int k, int s, int e, int a, int b, int v){
	prop(k,s,e);
	if(e<=a||s>=b)return;
	if(s>=a&&e<=b){lazy[k]^=v;prop(k,s,e);return;}
	int m=(s+e)/2;
	st_upd(2*k,s,m,a,b,v);
	st_upd(2*k+1,m,e,a,b,v);
	merge(st[2*k],st[2*k+1],st[k]);
}

void st_query(int k, int s, int e, int a, int b, int *r){
	if(e<=a||s>=b)return;
	prop(k,s,e);
	if(s>=a&&e<=b){merge(r,st[k],r);return;}
	int m=(s+e)/2;
	st_query(2*k,s,m,a,b,r);
	st_query(2*k+1,m,e,a,b,r);
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	st_init(1,0,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);l--;
		if(t==1){
			int w[20];
			memset(w,0,sizeof(w));
			st_query(1,0,n,l,r,w);
			ll t=0;
			fore(i,0,20)t+=(1LL<<i)*w[i];
			printf("%I64d\n",t);
		}
		else {
			int v;
			scanf("%d",&v);
			st_upd(1,0,n,l,r,v);
		}
	}
	return 0;
}