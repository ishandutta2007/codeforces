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

ll dp[360370];
ll a,b,k;

ll f(ll x){
	ll &r=dp[x];
	if(r>=0)return r;
	if(x==0){
		r=0; return r;
	}
	r=2e18;
	fore(i,2,k+1){
		if(x%i!=0)r=min(r,f(x-x%i)+1);
	}
	r=min(r,f(x-1)+1);
	return r;
}

ll dp2[360370];

ll f2(ll x){
	ll &r=dp2[x];
	if(r>=0)return r;
	if(x==b%360360){
		r=0; return r;
	}
	if(x<b%360360){
		r=2e18; return r;
	}
	r=2e18;
	fore(i,2,k+1){
		if(x%i!=0)r=min(r,f2(x-x%i)+1);
	}
	r=min(r,f2(x-1)+1);
	return r;
}

int main(){FIN;
	cin>>a>>b>>k;
	mset(dp,-1);
	mset(dp2,-1);
	//fore(i,0,a+1)cout<<f2(i)<<" "; cout<<"\n";
	//cout<<f2(a);
	if(a/360360==b/360360){
		cout<<f2(a%360360);
	}else{
		cout<<f(a%360360)+f2(360360)+f(360360)*(a/360360-b/360360-1);
	}
	return 0;
}