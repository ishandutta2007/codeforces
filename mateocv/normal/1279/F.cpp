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

ll n,k,la; 
string s;

const int MAXN=1000006;

ll c[MAXN];

pair<ll,ll> dp[MAXN][2];

ll m;

pair<ll,ll> f(ll x, ll b){
	pair<ll,ll> &res=dp[x][b];
	if(res.fst>=0)return res;
	if(x==n){
		return res={0,0};
	}
	res={f(x+1,b).fst+(b^c[x])*2,f(x+1,b).snd};
	res=min(res,{f(min(x+la,n),b).fst+m,1+f(min(x+la,n),b).snd});
	return res;
}

int main(){FIN;
	cin>>n>>k>>la>>s;
	fore(i,0,n)c[i]=('A'<=s[i]&&s[i]<='Z');
	ll res[2]={0,0};
	fore(b,0,2){
		//cout<<b<<":\n";
		ll l=0,r=n;
		while(l<=r){
			m=(l+r)/2;
			mset(dp,-1);
			auto va=f(0,b);
			//cout<<l<<" "<<r<<" "<<m<<" "<<va.fst<<" "<<va.snd<<endl;
			if(va.snd<=k){
				r=m-1;
			}else if(va.snd>k){
				l=m+1;
			}
		}
		mset(dp,-1);
		m=l;
		auto va=f(0,b);
		res[b]=(va.fst-k*m)/2;
	}
	cout<<min(res[0],res[1])<<"\n";
	
	return 0;
}