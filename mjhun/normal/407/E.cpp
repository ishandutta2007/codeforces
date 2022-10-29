#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;
#define INF (1LL<<60)

struct STree {
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,INF), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e){
		if(s+1==e){st[k]=-s;return;}
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
		st[k]=min(st[2*k],st[2*k+1]);
	}
	void push(int k, int s, int e){
		if(!lazy[k])return;
		st[k]+=lazy[k];
		if(s+1<e){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0;
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v;
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int b, ll v){ // rightmost pos < b tq val[pos] <= v
		push(k,s,e);
		if(st[k]>v||s>=b)return -1;
		if(s+1==e)return s;
		int m=(s+e)/2;
		int r=query(2*k+1,m,e,b,v);
		if(r<0)r=query(2*k,s,m,b,v);
		return r;
	}
	void init(){init(1,0,n);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int b, ll v){return query(1,0,n,b,v);}
};

int n,k;
ll d,x[200005];

int e[200005];

pair<int,int> solve(vector<ll>& v){
	int n=v.size();
	map<ll,int> l;
	e[n]=n;
	for(int i=n-1;i>=0;--i){
		e[i]=e[i+1];
		if(l.count(v[i]))e[i]=min(e[i],l[v[i]]);
		l[v[i]]=i;
	}
	STree w(n);w.init();
	stack<pair<ll,int> > s0,s1;
	s0.push(mp(-INF,n));
	s1.push(mp(INF,n));
	pair<int,int> r=mp(1,0);
	for(int i=n-1;i>=0;--i){
		while(v[i]<=s0.top().fst){
			pair<int,int> p=s0.top();s0.pop();
			w.upd(p.snd,s0.top().snd,p.fst-v[i]);
		}
		s0.push(mp(v[i],i));
		while(v[i]>=s1.top().fst){
			pair<int,int> p=s1.top();s1.pop();
			w.upd(p.snd,s1.top().snd,v[i]-p.fst);
		}
		s1.push(mp(v[i],i));
		int j=w.query(e[i],k-i);
		r=min(r,mp(i-j-1,i));
	}
	return r;
}

int main(){
	scanf("%d%d%lld",&n,&k,&d);
	fore(i,0,n)scanf("%lld",x+i);
	pair<int,int> r=mp(1,0); // -len, left
	if(d==0){
		int i=0;
		while(i<n){
			int j=i;
			while(j<n&&x[j]==x[i])j++;
			r=min(r,mp(i-j,i));
			i=j;
		}
	}
	else {
		fore(i,0,n)x[i]+=1LL<<30;
		int i=0;
		while(i<n){
			int j=i;
			vector<ll> v;
			while(j<n&&x[j]%d==x[i]%d)v.pb(x[j++]/d);
			pair<int,int> p=solve(v);
			p.snd+=i;
			r=min(r,p);
			i=j;
		}
	}
	printf("%d %d\n",r.snd+1,r.snd-r.fst);
	return 0;
}