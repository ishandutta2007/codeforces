#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define oper min
#define NEUT (1<<20)
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree st(300005);
int a[300005];
vector<int> w[300005];
int n;

void doit(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--,w[a[i]].pb(i);
	st.n=n;
	st.init(a);
	fore(i,0,n)reverse(w[i].begin(),w[i].end());
	bool r=true;
	fore(i,0,n){
		int t;
		scanf("%d",&t);t--;
		if(!r)continue;
		if(!SZ(w[t])){r=false;continue;}
		int k=w[t].back();w[t].pop_back();
		if(st.query(0,k)<t){r=false;continue;}
		st.upd(k,1e6);
	}
	fore(i,0,n)w[i].clear();
	puts(r?"YES":"NO");
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		doit();
	}
	return 0;
}