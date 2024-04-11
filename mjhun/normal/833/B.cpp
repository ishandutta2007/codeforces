#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define oper max
#define NEUT 0
struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	STree(){}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int n,k;
int a[35005],l[35005];

STree w;

int f[35005],f2[35005];

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	memset(l,-1,sizeof(l));
	int q=0;
	w=STree(n+1);
	fore(i,0,n){
		if(l[a[i]]<0)q++;
		l[a[i]]=i;
		f[i+1]=q;
	}
	fore(i,1,k){
		w.init(f);
		memset(l,-1,sizeof(l));
		fore(i,0,n){
			w.upd(l[a[i]]+1,i+1,1);
			l[a[i]]=i;
			f2[i+1]=w.query(0,i+1);
		}
		memcpy(f,f2,sizeof(f));
	}
	printf("%d\n",f[n]);
	return 0;
}