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

vector<ll> a;

const ll MOD=998244353;

const int MAXN=200005;

ll dp[MAXN],sump[MAXN],dpf[MAXN];

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	vector<pair<ll,ll>> st;
	ll ss=0;
	sump[0]=1;
	fore(i,0,n){
		pair<ll,ll> p={a[i],i};
		while(SZ(st)&&st.back()>p){
			ss=(ss+MOD-dpf[st.back().snd])%MOD;
			st.pop_back();
		}
		if(SZ(st)){
			//cout<<(sump[i]-sump[st.back().snd]+MOD)%MOD<<"\n";
			dpf[i]=(2ll*MOD-a[i])*(sump[i]-sump[st.back().snd]+MOD)%MOD;
		}else{
			dpf[i]=(2ll*MOD-a[i])*(sump[i])%MOD;
		}
		//cout<<i<<" "<<dp[i]<<"\n";
		//if(!(i&1))dp[i]=(MOD-dp[n-1])%MOD;
		dp[i]=(dpf[i]+ss)%MOD;
		//cout<<i<<" "<<dp[i]<<"\n";
		sump[i+1]=(sump[i]+dp[i])%MOD;
		ss=(ss+dpf[i])%MOD;
		st.pb(p);
	}
	ll res=dp[n-1];
	if(n&1)res=(MOD-res)%MOD;
	cout<<res<<"\n";
	return 0;
}