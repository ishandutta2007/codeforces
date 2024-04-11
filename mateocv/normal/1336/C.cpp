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

string s,t;
const ll MOD = 998244353;

ll dp[3030][3030];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	ll pos=y-x-1;
	if(pos==SZ(s))return r=1;
	r=(x==0&&y<=SZ(s)&&t[y-1]=='.');
	if(x>0)if(t[x-1]=='.'||t[x-1]==s[pos])r=(r+f(x-1,y))%MOD;
	if(y<=SZ(s))if(t[y-1]=='.'||t[y-1]==s[pos])r=(r+f(x,y+1))%MOD;
	//cout<<x<<" "<<y<<" "<<r<<"\n";
	return r;
}

int main(){FIN;
	cin>>s>>t;
	while(SZ(t)<SZ(s))t.pb('.');
	//reverse(ALL(s));
	mset(dp,-1);
	ll res=0;
	fore(i,0,SZ(s)+1)res=(res+f(i,i+1))%MOD;
	cout<<res;
	return 0;
}