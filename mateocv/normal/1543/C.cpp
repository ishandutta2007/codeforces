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

ld EPS=1e-9;

ld solve(ld a, ld c, ld v, ll it){
	if(it==0)return 0.;
	ld res=0.;
	if(a>EPS){
		if(a>v+EPS)res+=a*(solve(a-v,c+v,v,it-1)+1);
		else res+=a*(solve(0,1,v,it-1)+1);
	}
	res+=c;
	//cout<<a<<" "<<c<<" "<<v<<" "<<it<<" "<<res<<"\n";
	return res;
}

ld solve(ld a, ld b, ld c, ld v, ll it){
	//cout<<a<<" "<<b<<" "<<c<<" "<<v<<" "<<it<<"\n";
	if(it==0)return 0.;
	ld res=0.;
	if(a>EPS){
		if(a>v+EPS)res+=a*(solve(a-v,b+v/2,c+v/2,v,it-1)+1);
		else res+=a*(solve(b+a/2,c+a/2,v,it-1)+1);
	}
	if(b>EPS){
		if(b>v+EPS)res+=b*(solve(a+v/2,b-v,c+v/2,v,it-1)+1);
		else res+=b*(solve(a+b/2,c+b/2,v,it-1)+1);
	}
	res+=c;
	//cout<<a<<" "<<b<<" "<<c<<" "<<v<<" "<<it<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ld a,b,c,v; cin>>a>>b>>c>>v;
		cout<<fixed<<setprecision(15)<<solve(a,b,c,v,100000)<<"\n";
	}
	
	return 0;
}