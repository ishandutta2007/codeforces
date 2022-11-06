#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r+1<<endl;
	ll resp; cin>>resp;
	if(resp==-1)exit(0);
	return resp;
}

ll tri(ll n){
	ll s=sqrt(2ll*n);
	fore(i,max(2ll,s-5),s+5){
		if(i*(i-1)/2==n)return i;
	}
	return -1;
}

ll tom2(ll n){
	return n*(n-1)/2;
}

ll n; 

ll solve2(ll pos, ll l, ll r, bool bo){
	//cout<<pos<<" "<<l<<" "<<r<<" "<<bo<<endl;
	if(!bo){
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(pos,m)==tom2(m-pos+1))l=m+1;
			else r=m-1;
		}
	}else{
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(m,pos)==tom2(pos-m+1))r=m-1;
			else l=m+1;
		}
	}
	return l;
}

vector<ll> solve(ll l, ll r, ll c){
	//cout<<l<<" "<<r<<" "<<c<<endl;
	ll m=(l+r)/2;
	auto a=ask(l,m);
	if(a==0)return solve(m-1,r,c);
	else if(a==c)return solve(l,m,c);
	else{
		auto x=tri(a);
		if(x!=-1&&m-x+1>=0&&ask(m-x+1,m)==a){
			auto p=solve2(m-x+1,m-x+2,r,0);
			return {m-x+1,p,p+tri(ask(p,n-1))-1};
		}else{
			auto y=tri(ask(m,n-1));
			assert(y!=-1);
			auto p=solve2(m+y-1,l,m+y-2,1);
			return {p-tri(ask(0,p-1)),p,m+y-1};
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		auto a=ask(0,n-1);
		auto res=solve(0,n-1,a);
		cout<<"! ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<endl;
	}
	
	return 0;
}