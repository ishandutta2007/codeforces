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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

template<class T>
struct STree {
	vector<T> st;int n;
	void init(int k, int s, int e, vector<T>& a){
		if(s+1==e)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a);init(2*k+1,m,e,a);
			st[k]=min(st[2*k],st[2*k+1]);
		}
	}
	int query0(int k, int s, int e, int b, T v){
		if(s>=b||st[k]>=v)return s;
		if(s+1==e)return e;
		int m=(s+e)/2;
		int r=query0(2*k+1,m,e,b,v);
		if(r==m)r=query0(2*k,s,m,b,v);
		return r;
	}
	int query1(int k, int s, int e, int a, T v){
		if(e<=a||st[k]>=v)return e;
		if(s+1==e)return s;
		int m=(s+e)/2;
		int r=query1(2*k,s,m,a,v);
		if(r==m)r=query1(2*k+1,m,e,a,v);
		return r;
	}
	T query(int k, int s, int e, int a, int b){
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		if(m>a&&m<b)return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
		else if(m>a)return query(2*k,s,m,a,b);
		return query(2*k+1,m,e,a,b);
	}
	void upd(int k, int s, int e, int p, T v){
		if(s+1==e){st[k]=v;}
		else {
			int m=(s+e)/2;
			if(p<m)upd(2*k,s,m,p,v);
			else upd(2*k+1,m,e,p,v);
			st[k]=min(st[2*k],st[2*k+1]);
		}
	}
	void init(vector<T>& a){
		st.resize(4*SZ(a));n=SZ(a);
		init(1,0,n,a);
	}
	int query0(int b, T v){return query0(1,0,n,b,v);}
	int query1(int a, T v){return query1(1,0,n,a,v);}
	T query(int a, int b){return query(1,0,n,a,b);}
	void upd(int p, T v){return upd(1,0,n,p,v);}
};

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string& s){
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||r[sa[i]+k]!=r[sa[i-1]+k])rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp;
}

char t[500005];
string s;
vector<int> p;
int rs[1<<20],v[1<<20];
vector<int> sa,lcp;
int n,m;
STree<int> s0;STree<pair<int,int> > s1;
int c[1<<19];

void init(){
	vector<pair<int,int> > t(m);
	fore(i,0,m)t[i]=mp(0,i);
	s1.init(t);
}
void add(int k){
	if(v[k]<0)return;
	k=v[k];
	c[k]++;
	s1.upd(k,mp(-c[k],k));
}
void remove(int k){
	if(v[k]<0)return;
	k=v[k];
	c[k]--;
	s1.upd(k,mp(-c[k],k));
}
pair<int,int> get_ans(int a, int b){
	auto p=s1.query(a,b);
	return mp(p.snd,-p.fst);
}

int sq,nq;
struct qu{int l,r,id,a,b;};
qu qs[1<<19];
pair<int,int> ans[1<<19];
bool qcomp(const qu &a, const qu &b){
	if(a.l/sq!=b.l/sq) return a.l<b.l;
	return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	sq=sqrt(n)+.5;
	sort(qs,qs+nq,qcomp);
	int l=0,r=0;
	init();
	fore(i,0,nq){
		qu q=qs[i];
		while(l>q.l)add(--l);
		while(r<q.r)add(r++);
		while(l<q.l)remove(l++);
		while(r>q.r)remove(--r);
		ans[q.id]=get_ans(q.a,q.b);
	}
}

int main(){
	scanf("%s",t);
	for(int i=0;t[i];++i)s.pb(t[i]);
	p.pb(SZ(s));s.pb('#');
	scanf("%d",&m);
	fore(i,0,m){
		scanf("%s",t);
		for(int i=0;t[i];++i)s.pb(t[i]);
		p.pb(SZ(s));s.pb('#');
	}
	n=SZ(s);
	sa=constructSA(s);
	fore(i,0,n)rs[sa[i]]=i;
	fore(i,0,n){
		v[i]=lower_bound(p.begin(),p.end(),sa[i])-p.begin();
		if(sa[i]==p[v[i]])v[i]=0;
		v[i]--;
	}
	lcp=computeLCP(s,sa);
	s0.init(lcp);
	scanf("%d",&nq);
	fore(i,0,nq){
		int a,b,l,r;
		scanf("%d%d%d%d",&a,&b,&l,&r);a--;l--;
		int k=rs[l];
		int ss=s0.query0(k+1,r-l)-1,e=s0.query1(k+1,r-l);
		qs[i]={ss,e,i,a,b};
	}
	mos();
	fore(i,0,nq)printf("%d %d\n",ans[i].fst+1,ans[i].snd);
	return 0;
}