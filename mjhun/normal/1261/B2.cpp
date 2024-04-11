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

#define oper(a,b) (a+b)
#define NEUT 0
struct STree {
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int t){ // t-esimo 1
		if(s+1==e)return s;
		int m=(s+e)/2;
		if(st[2*k]>t)return query(2*k,s,m,t);
		return query(2*k+1,m,e,t-st[2*k]);
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int t){return query(1,0,n,t);}
};

vector<pair<int,int> > v; // -num,pos
int res[200005];
int a[200005];
vector<pair<int,int> > q[200005];
int n,m;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",a+i);
		v.pb(mp(-a[i],i));
	}
	scanf("%d",&m);
	fore(i,0,m){
		int k,p;
		scanf("%d%d",&k,&p);p--;
		q[k].pb(mp(p,i));
	}
	sort(v.begin(),v.end());
	STree st(n);
	fore(i,0,n){
		st.upd(v[i].snd,1);
		for(auto p:q[i+1]){
			int k=p.fst;
			res[p.snd]=a[st.query(k)];
		}
	}
	fore(i,0,m)printf("%d\n",res[i]);
	return 0;
}