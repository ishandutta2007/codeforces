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
typedef long double ld;

ld EPS0=1e-10,EPS1=1e-13;

ld ask(vector<pair<ld,ld>> v, ll sw){
	cout<<"? "<<SZ(v)<<endl;
	for(auto i:v){
		if(sw)swap(i.fst,i.snd);
		cout<<i.fst<<" "<<i.snd<<endl;
	}
	ld res; cin>>res;
	return res;
}

ld solve(ll n, ll m, ll sw){
	vector<pair<ld,ld>> v1;
	v1.pb({n,0});
	fore(i,1,m+1)v1.pb({0,i}),v1.pb({n,i});
	v1.pop_back();
	v1.pb({n+1,m});
	v1.pb({n+1,0});
	auto a=ask(v1,sw);
	return a*n-0.5;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ld x=solve(n,m,0);
	ld y=solve(m,n,1);
	cout<<fixed<<setprecision(15)<<"! "<<x<<" "<<y<<endl;
	
	return 0;
}