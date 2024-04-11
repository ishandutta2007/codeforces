#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1))%mod;
}

ll inv(ll x){
	return pot(x, mod-2);
}

ll lolsum(ll k, ll a, ll b, ll x, ll y){
	ll re=a*(((6ll*b)%mod-((3ll*k*y)%mod)+mod)%mod)+((k*x)%mod)*(((-3ll*b+mod)%mod+(2ll*k*y)%mod+y)%mod);
	re%=mod;
	re*=(ll)(k+1);
	re%=mod;
	re*=inv(6);
	re%=mod;
	return re;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll h,w;
	cin>>n>>h>>w;
	string s;
	cin>>s;
	ll y=0;
	ll x=0;
	ll xmi=0;
	ll xma=0;
	ll ymi=0;
	ll yma=0;
	ll tw=0;
	ll th=0;
	ll kw=0;
	ll kh=0;
	ll v=0;
	for (int i=0;i<2*n;i++){
		xmi=min(xmi, x);
		xma=max(xma, x);
		ymi=min(ymi, y);
		yma=max(yma, y);
		tw=xma-xmi+1;
		th=yma-ymi+1;
		if (tw>w||th>h){
			break;
		}
		if (i==n){
			if (x==0&&y==0){
				cout<<-1<<endl;
				return 0;
			}
			kw=llabs(x);
			kh=llabs(y);
		}
		if (i<n){
			v+=(w-tw+1ll)*(h-th+1ll);
			v%=mod;
		}
		else{
			ll ww=(w-tw+1ll);
			ll hh=(h-th+1ll);
			ll rs=0;
			if (kw==0){
				rs=(hh/kh);
			}
			else if(kh==0){
				rs=(ww/kw);
			}
			else{
				rs=min(ww/kw, hh/kh);
			}
			v+=lolsum(rs, ww, hh, kw, kh);
			v%=mod;
		}
		if (s[i%n]=='U') y--;
		if (s[i%n]=='D') y++;
		if (s[i%n]=='L') x--;
		if (s[i%n]=='R') x++;
	}
	cout<<v<<endl;
}