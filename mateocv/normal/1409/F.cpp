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
string s,t;

ll dp[202][202][202];

ll f(ll x, ll y, ll z){
	ll &res=dp[x][y][z];
	if(res>=0)return res;
	if(x==n){
		return res=0;
	}
	res=0;
	if(s[x]!=t[0]&&s[x]!=t[1]){
		res=max(res,f(x+1,y,z));
	}
	if(s[x]==t[0]||z!=0){
		res=max(res,f(x+1,y+1,z-(s[x]!=t[0])));
	}
	if(s[x]==t[1]||z!=0){
		res=max(res,f(x+1,y+(t[0]==t[1]),z-(s[x]!=t[1]))+y);
	}
	//cout<<x<<" "<<y<<" "<<z<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n>>k>>s>>t;
	mset(dp,-1);
	cout<<f(0,0,k)<<"\n";
	
	return 0;
}