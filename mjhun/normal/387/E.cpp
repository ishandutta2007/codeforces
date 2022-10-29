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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

#define MAXN (1<<20)

int ft[MAXN+1];
void upd(int i0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){return get(i1)-get(i0);}

int a[1<<20],st[1<<22];
void st_init(int k, int s, int e){
	if(s+1==e)st[k]=a[s];
	else {
		int m=(s+e)/2;
		st_init(2*k,s,m);
		st_init(2*k+1,m,e);
		st[k]=min(st[2*k],st[2*k+1]);
	}
}
void st_upd(int k, int s, int e, int p){
	if(s+1==e)st[k]=a[p];
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p);
		else st_upd(2*k+1,m,e,p);
		st[k]=min(st[2*k],st[2*k+1]);
	}
}
int asd;
pair<int,int> st_query(int k, int s, int e, int p){
	asd++;
	if(st[k]>=a[p])return mp(s,e);
	if(s+1==e)return mp(-1,-1);
	int m=(s+e)/2;
	if(e<=p){
		auto t=st_query(2*k+1,m,e,p);
		if(t.fst==m){
			auto t0=st_query(2*k,s,m,p);
			if(t0.snd==m)t.fst=t0.fst;
		}
		return t;
	}
	else if(s>=p){
		auto t=st_query(2*k,s,m,p);
		if(t.snd==m){
			auto t0=st_query(2*k+1,m,e,p);
			if(t0.fst==m)t.snd=t0.snd;
		}
		return t;
	}
	else if(p<m){
		auto t=st_query(2*k,s,m,p);
		if(t.snd==m){
			auto t0=st_query(2*k+1,m,e,p);
			if(t0.fst==m)t.snd=t0.snd;
		}
		return t;
	}
	else {
		auto t=st_query(2*k+1,m,e,p);
		if(t.fst==m){
			auto t0=st_query(2*k,s,m,p);
			if(t0.snd==m)t.fst=t0.fst;
		}
		return t;
	}
}

int n,k;
bool h[1<<20];
vector<pair<int,int> > w;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	fore(i,0,k){
		int x;
		scanf("%d",&x);x--;
		h[x]=true;
	}
	st_init(1,0,n);
	fore(i,0,n)if(!h[a[i]])w.pb(mp(a[i],i));
	sort(w.begin(),w.end());
	ll r=0;
	for(auto _:w){
		int i=_.snd;
		asd=0;
		auto p=st_query(1,0,n,i);
		//assert(asd<64);
		r+=p.snd-p.fst-get_sum(p.fst,p.snd);
		a[i]=1<<30;
		st_upd(1,0,n,i);
		upd(i,1);
	}
	printf("%lld\n",r);
	return 0;
}