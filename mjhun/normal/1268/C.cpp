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
	STree(){}
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
	int get(int k, int s, int e, int t){
		if(s+1==e)return s;
		int m=(s+e)/2;
		if(st[2*k]>t)return get(2*k,s,m,t);
		return get(2*k+1,m,e,t-st[2*k]);
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
	int get(int k){return get(1,0,n,k);}
};

int n;
int p[200005];
ll s;
STree st;

int main(){
	scanf("%d",&n);
	st=STree(n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);x--;
		p[x]=i;
	}
	fore(i,0,n){
		int t=p[i];
		int k=st.query(0,t);
		st.upd(t,1);
		s+=i-k;
		ll r;
		if(i%2==0){
			if(k<i/2){
				s-=t;
				s+=st.get(i/2);
			}
			else if(k>i/2){
				s+=t;
				s-=st.get(i/2);
			}
			int q=i/2;
			r=s-1LL*q*(q+1);
		}
		else {
			if(k<=i/2){
				s-=t;
				s+=st.get(i/2+1);
			}
			else {
				s+=t;
				s-=st.get(i/2);
			}
			int q=i/2+1;
			r=s-1LL*q*(q-1)-q;
		}
		if(i)putchar(' ');
		printf("%lld",r);
	}
	puts("");
	return 0;
}