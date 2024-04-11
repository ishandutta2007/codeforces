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

ll n,k; 

vector<pair<ll,ll>> a;

ll findpos(ll x){
	return lower_bound(ALL(a),pair<ll,ll>({x,-1}))-a.begin();
}

ll findk(ll l, ll r, ll val, ll b, ll kk){
	if(l==r)return -1;
	if(b==-1)return a[l].snd;
	ll pot=(1ll<<b);
	ll vl=kk;
	ll vm=vl+pot;
	ll vr=vm+pot;
	ll nl=max(findpos((pot&val)?vl:vm),l);
	ll nr=min(findpos((pot&val)?vm:vr),r);
	ll res=-1;
	if(k&pot){
		res=findk(nl,nr,val,b-1,kk+((pot&val)?0:pot));
	}else{
		if(nl<nr)res=a[nl].snd;
		else res=findk(l,r,val,b-1,kk+((pot&val)?pot:0));
	}
	//cout<<l<<" "<<r<<" "<<val<<" "<<b<<" "<<kk<<" : "<<res<<"\n";
	return res;
}

vector<ll> solve(ll l, ll r, ll b){
	if(l==r)return {};
	vector<ll> res;
	if(b==-1){
		fore(i,l,r)res.pb(a[i].snd);
	}else{
		ll kk=a[l].fst;
		fore(i,0,b+1){
			if((1ll<<i)&kk)kk^=(1ll<<i);
		}
		if(k&(1ll<<b)){
			fore(i,l,r){
				auto f=findk(l,r,a[i].fst,b,kk);
				if(f!=-1){
					res={a[i].snd,f};
					break;
				}
			}
			if(!SZ(res))res={a[l].snd};
		}else{
			kk^=(1ll<<b);
			auto pos=findpos(kk);
			res=solve(l,pos,b-1);
			auto s=solve(pos,r,b-1);
			for(auto i:s)res.pb(i);
		}
	}
	/*
	cout<<l<<" "<<r<<" "<<b<<": ";
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	*/
	return res;
}

int main(){FIN;
	cin>>n>>k;
	a.resize(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	if(k==0){
		cout<<n<<"\n";
		fore(i,0,n)cout<<i+1<<" ";
		cout<<"\n";
		return 0;
	}
	sort(ALL(a));
	auto res=solve(0,n,29);
	if(SZ(res)>=2){
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}else cout<<"-1\n";
	
	
	return 0;
}