#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<pair<pair<ll,ll>,ll>> res;

void solve(ll l, ll r, vector<pair<ll,ll>> v){
	//cout<<l<<" "<<r<<" ";
	//for(auto i:v)cout<<"("<<i.fst<<","<<i.snd<<") ";
	//cout<<endl;
	vector<pair<ll,ll>> ev;
	for(auto i:v)ev.pb({i.fst,1}),ev.pb({i.snd+1,-1});
	sort(ALL(ev));
	vector<ll> c(r+1);
	ll va=0,ul=0;
	fore(i,l,r+1){
		while(ul<SZ(ev)&&ev[ul].fst<=i){
			va+=ev[ul].snd;
			ul++;
		}
		c[i]=va;
	}
	ll pos=-1;
	fore(i,l,r+1){
		if(c[i]==1)pos=i;
	}
	//cout<<pos<<endl;
	assert(pos!=-1);
	res.pb({{l,r},pos});
	vector<pair<ll,ll>> vr[2];
	for(auto i:v){
		if(i==pair<ll,ll>({l,r}))continue;
		if(i.snd<pos)vr[0].pb(i);
		else vr[1].pb(i);
	}
	if(l<=pos-1)solve(l,pos-1,vr[0]);
	if(r>=pos+1)solve(pos+1,r,vr[1]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].fst--,a[i].snd--;
		res.clear();
		solve(0,n-1,a);
		for(auto i:res)cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}