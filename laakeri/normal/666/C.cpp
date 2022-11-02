#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
ll pot(ll x, ll p) {
	if (p==0) return 1;
	if (p%2==0) {
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1))%mod;
}
ll inv(ll x){
	return pot(x, mod-2);
}
vector<pair<int, int> > qs[101010];
int v[101010];

ll ke[202020];
ll ike[202020];
ll po[202020];

ll ncr(ll n, ll k){
	return (ke[n]*((ike[k]*ike[n-k])%mod))%mod;
}

void go(int x){
	sort(qs[x].begin(), qs[x].end());
	int i2=0;
	while (i2<(int)qs[x].size()&&qs[x][i2].F<x){
		v[qs[x][i2].S]=0;
		i2++;
	}
	ll vv=1;
	ll su=1;
	for (ll i=x;i2<(int)qs[x].size();i++){
		while (i2<(int)qs[x].size()&&qs[x][i2].F==i){
			v[qs[x][i2].S]=su;
			i2++;
		}
		vv=su+ncr(i, x-1)*po[i-x+1];
		vv%=mod;
		
		su*=25;
		su+=vv;
		su%=mod;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ke[0]=1;
	ike[0]=1;
	po[0]=1;
	for (int i=1;i<=200000;i++){
		ke[i]=ke[i-1]*(ll)i;
		ke[i]%=mod;
		ike[i]=inv(ke[i]);
		po[i]=po[i-1]*25;
		po[i]%=mod;
	}
	int m;
	cin>>m;
	string s;
	cin>>s;
	int le=s.size();
	int vi=0;
	for (int i=0;i<m;i++){
		int t;
		cin>>t;
		if (t==1){
			cin>>s;
			le=s.size();
		}
		else {
			int n;
			cin>>n;
			qs[le].push_back({n, vi++});
		}
	}
	for (int i=0;i<=100000;i++){
		if ((int)qs[i].size()>0){
			go(i);
		}
	}
	for (int i=0;i<vi;i++){
		cout<<v[i]<<'\n';
	}
}