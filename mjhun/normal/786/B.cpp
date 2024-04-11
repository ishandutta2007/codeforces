#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1LL<<61)
using namespace std;
typedef long long ll;

pair<int,int> st0[400005];

void st_upd0(int k, int s, int e, int p, int v){
	if(s+1==e)st0[k]=mp(v,p);
	else {
		int m=(s+e)/2;
		if(p<m)st_upd0(2*k,s,m,p,v);
		else st_upd0(2*k+1,m,e,p,v);
		st0[k]=max(st0[2*k],st0[2*k+1]);
	}
}
pair<int,int> st_query0(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return mp(-1,-1);
	if(s>=a&&e<=b)return st0[k];
	int m=(s+e)/2;
	return max(st_query0(2*k,s,m,a,b),st_query0(2*k+1,m,e,a,b));
}

ll st1[400005];
ll lazy[400005];
void push1(int k, int s, int e){
	if(lazy[k]<0)return;
	if(st1[k]<INF)st1[k]=min(st1[k],lazy[k]);
	if(s+1<e){
		if(lazy[2*k]<0)lazy[2*k]=lazy[k];
		else lazy[2*k]=min(lazy[2*k],lazy[k]);
		if(lazy[2*k+1]<0)lazy[2*k+1]=lazy[k];
		else lazy[2*k+1]=min(lazy[2*k+1],lazy[k]);
	}
	lazy[k]=-1;
}
void st_upd1(int k, int s, int e, int a, int b, ll v){
	push1(k,s,e);
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b){
		if(lazy[k]<0)lazy[k]=v;
		else lazy[k]=min(lazy[k],v);
		push1(k,s,e);return;
	}
	int m=(s+e)/2;
	st_upd1(2*k,s,m,a,b,v);st_upd1(2*k+1,m,e,a,b,v);
	st1[k]=min(st1[2*k],st1[2*k+1]);
}
void st_upd2(int k, int s, int e, int p, ll v){
	push1(k,s,e);
	if(s+1==e)st1[k]=v;
	else {
		int m=(s+e)/2;
		if(p<m)st_upd2(2*k,s,m,p,v);
		else st_upd2(2*k+1,m,e,p,v);
		st1[k]=min(st1[2*k],st1[2*k+1]);
	}
}
int st_query1(int k, int s, int e){
	push1(k,s,e);
	if(s+1==e)return s;
	int m=(s+e)/2;
	push1(2*k,s,m);
	push1(2*k+1,m,e);
	if(st1[2*k]<st1[2*k+1])return st_query1(2*k,s,m);
	return st_query1(2*k+1,m,e);
}

int n,q,s;
vector<pair<pair<int,pair<int,int> >,int> > e2;
vector<pair<pair<pair<int,int>,int>,int> > e3;
vector<pair<pair<int,int>,int> > x3;
vector<int> g2[100005];
ll d[100005];

int main(){
	scanf("%d%d%d",&n,&q,&s);s--;
	fore(i,0,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);x--;y--;
			e2.pb(mp(mp(x,mp(y,y+1)),c));
		}
		else {
			int x,l,r,c;
			scanf("%d%d%d%d",&x,&l,&r,&c);x--;l--;
			if(t==2)e2.pb(mp(mp(x,mp(l,r)),c));
			else e3.pb(mp(mp(mp(l,r),x),c));
		}
	}
	fill(st0,st0+400005,mp(-1,-1));
	fore(_,0,e3.size()){
		auto p=e3[_];
		int l=p.fst.fst.fst;
		int r=p.fst.fst.snd;
		x3.pb(mp(mp(l,r),_));
	}
	sort(x3.begin(),x3.end());
	fore(_,0,x3.size()){
		auto p=x3[_];
		int l=p.fst.fst,r=p.fst.snd,i=p.snd;
		st_upd0(1,0,q,_,r);
	}
	fore(_,0,e2.size()){
		auto p=e2[_];
		int x=p.fst.fst;
		g2[x].pb(_);
	}
	fill(d,d+n,INF);
	fill(st1,st1+400005,INF-1);
	memset(lazy,-1,sizeof(lazy));
	st_upd2(1,0,n,s,0);
	int x;
	while(x=st_query1(1,0,n),st1[1]<INF-1){
		d[x]=st1[1];
		st_upd2(1,0,n,x,INF);
		for(int k:g2[x]){
			auto p=e2[k];
			int l=p.fst.snd.fst,r=p.fst.snd.snd,c=p.snd;
			st_upd1(1,0,n,l,r,d[x]+c);
		}
		int j=lower_bound(x3.begin(),x3.end(),mp(mp(x+1,-11),-11))-x3.begin();
		pair<int,int> p;
		while(p=st_query0(1,0,q,0,j),p.fst>x){
			int k=p.snd;
			st_upd0(1,0,q,k,-1);
			int kk=x3[k].snd;
			auto q=e3[kk];
			int y=q.fst.snd;
			int c=q.snd;
			st_upd1(1,0,n,y,y+1,d[x]+c);
		}
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%lld",d[i]<INF?d[i]:-1LL);
	}puts("");
	return 0;
}