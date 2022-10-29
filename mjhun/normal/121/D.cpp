#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1LL<<60)
using namespace std;
typedef long long ll;

ll add(ll a, ll b){assert(a>=0&&b>=0);return min(a+b,INF);}
ll mul(ll a, ll b){
	assert(a>=0&&b>=0);
	ll c=a*b;
	if(a!=0&&(c%a||c/a!=b))return INF;
	return min(c,INF);
}

vector<ll> v,q0,q1;
ll a[100005],b[100005];
int n;ll k,l;
vector<pair<ll,int> > e;

void gen(ll x){
	if(x>1000000000000000000LL)return;
	v.pb(x);
	gen(10*x+4);gen(10*x+7);
}

int main(){
	gen(4);gen(7);
	sort(v.begin(),v.end());
	scanf("%d%lld",&n,&k);
	l=1LL<<60;
	fore(i,0,n)scanf("%lld%lld",a+i,b+i),l=min(l,b[i]-a[i]);
	q0=vector<ll>(v.size());q1=vector<ll>(v.size());
	fore(i,0,v.size())e.pb(mp(v[i],i));
	fore(i,0,n)e.pb(mp(b[i],-1));
	sort(e.begin(),e.end());
	ll c=0,lx=0,q=0;
	for(auto p:e){
		q=add(q,mul(c,p.fst-lx));
		lx=p.fst;
		if(p.snd<0)c++;
		else q0[p.snd]=q;
	}
	e.clear();
	fore(i,0,v.size())e.pb(mp(v[i],i));
	fore(i,0,n)e.pb(mp(a[i],-1));
	sort(e.begin(),e.end());reverse(e.begin(),e.end());
	c=0;lx=INF;q=0;
	for(auto p:e){
		q=add(q,mul(c,lx-p.fst));
		lx=p.fst;
		if(p.snd<0)c++;
		else q1[p.snd]=q;
	}
	int j=0,r=0;
	fore(i,0,v.size()){
		if(j<i)j=i;
		while(j<v.size()&&v[j]-v[i]<=l&&add(q1[i],q0[j])<=k)j++;
		r=max(r,j-i);
	}
	printf("%d\n",r);
	return 0;
}