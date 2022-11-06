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

const int MAXN=(1ll<<21);

ll sum[MAXN],mins[22];

vector<vector<ll>> vm;

ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==(1ll<<SZ(vm))-1)return res=0;
	res=0;
	ll s=sum[x];
	fore(i,0,SZ(vm)){
		if(!((1ll<<i)&x)){
			ll val=0;
			if(mins[i]+s<=0){
				val+=vm[i][s];
			}
			if(mins[i]+s>=0){
				val+=f(x^(1ll<<i));
			}
			res=max(res,val);
		}
	}
	//cout<<x<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<string> s(n);
	fore(i,0,n)cin>>s[i];
	vm.resize(n);
	fore(i,0,n){
		//cout<<i<<":\n";
		ll mini=0,va=0;
		vm[i]={0};
		for(auto j:s[i]){
			if(j=='(')va++;
			else va--;
			if(va==mini)vm[i].back()++;
			if(va<mini)vm[i].pb(1);
			mini=min(mini,va);
		}
		mins[i]=mini;
		sum[(1ll<<i)]=va;
		//for(auto j:vm[i])cout<<j<<" ";
		//cout<<"\n"<<mini<<" "<<va<<"\n";
	}
	fore(i,1,(1ll<<n)){
		//if(__builtin_popcount(i)==1)continue;
		fore(j,0,n){
			if((1ll<<j)&i){
				sum[i]=sum[i^(1ll<<j)]+sum[(1ll<<j)];
			}
		}
	}
	mset(dp,-1);
	cout<<f(0)<<"\n";
	
	return 0;
}