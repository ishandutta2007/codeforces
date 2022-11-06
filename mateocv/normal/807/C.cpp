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
typedef __int128 ll;

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return {p,{-b,a}}; // solutions: p+t*ans.snd
}

ll ce(ll a, ll b){
	//cout<<a<<" "<<b<<" ";
	assert(b!=0);
	if(b<0){
		a*=-1; b*=-1;
	}
	if(a>=0){
		//cout<<(a+b-1)/b<<"\n";
		return (a+b-1)/b;
	}else{
		//cout<<(-((-a)/b))<<"\n";
		return -((-a)/b);
	}
}

void print(__int128 n){
    if(n==0){
        cout<<0; return;
    }
	string res;
	while(n>0){
		res.pb('0'+n%10);
		n/=10;
	}
	reverse(ALL(res));
	cout<<res;
}

int main(){FIN;
	int t; cin>>t;
	while(t--){
		long long x,y,p,q; cin>>x>>y>>p>>q;
		if(p==0){
			if(x==0){
				cout<<"0\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		if(p==q){
			if(x==y){
				cout<<"0\n";
			}else{
				cout<<"-1\n";
			}
			continue;
		}
		auto d=diophantine(q,-p,y*p-x*q);
		//cout<<d.fst.fst<<" "<<d.fst.snd<<" "<<d.snd.fst<<" "<<d.snd.snd<<"\n";
		if(d.snd.snd<0){
			d.snd.snd*=-1;
			d.snd.fst*=-1;
		}
		ll tt=max(ce(-d.fst.fst,d.snd.fst),ce(d.fst.fst-d.fst.snd,d.snd.snd-d.snd.fst));
		//cout<<tt<<" "<<ce(-d.fst.fst,d.snd.fst)<<" "<<ce(d.fst.fst-d.fst.snd,d.snd.snd-d.snd.fst)<<"\n";
		__int128 res=tt;
		res*=d.snd.snd;
		res+=d.fst.snd;
		print(res);
		cout<<"\n";
	}
	
	return 0;
}