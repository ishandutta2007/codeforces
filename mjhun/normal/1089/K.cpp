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

pair<ll,ll> merge(pair<ll,ll> a, pair<ll,ll> b){
	auto p=mp(a.fst+max(b.fst-a.snd,0LL),b.snd+max(a.snd-b.fst,0LL));
	//printf(" %lld %lld  %lld %lld  %lld %lld\n",a.fst,a.snd,b.fst,b.snd,p.fst,p.snd);
	return p;
}

pair<ll,ll> st[1<<21];

void st_init(int k, int s, int e){
	st[k]=mp(e-s,0);
	if(s+1==e)return;
	int m=(s+e)/2;
	st_init(2*k,s,m);st_init(2*k+1,m,e);
}

void st_upd(int k, int s, int e, int p, int v){
	if(s+1==e){
		if(v)st[k]=mp(0,v-1);
		else st[k]=mp(1,0);
		return;
	}
	int m=(s+e)/2;
	if(p<m)st_upd(2*k,s,m,p,v);
	else st_upd(2*k+1,m,e,p,v);
	st[k]=merge(st[2*k],st[2*k+1]);
}

pair<ll,ll> st_query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return mp(0,0);
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return merge(st_query(2*k,s,m,a,b),st_query(2*k+1,m,e,a,b));
}

#define N 1000006

int tt[300005];
int pingo[1<<20];

int main(){
	int q;
	scanf("%d",&q);
	st_init(1,0,N);
	fore(_,1,q+1){
		char s[4];
		scanf("%s",s);
		if(s[0]=='+'){
			int d;
			scanf("%d%d",tt+_,&d);
			pingo[tt[_]]=d;
			st_upd(1,0,N,tt[_],d);
		}
		else if(s[0]=='-'){
			int i;
			scanf("%d",&i);
			pingo[tt[i]]=0;
			st_upd(1,0,N,tt[i],0);
		}
		else {
			int t;
			scanf("%d",&t);
			auto p=st_query(1,0,N,0,t);
			printf("%lld\n",p.snd+pingo[t]);
		}
	}
	return 0;
}