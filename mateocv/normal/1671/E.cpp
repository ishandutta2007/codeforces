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

ll n;

string s;

const ll MOD=998244353,P=1777771;

vector<pair<ll,ll>> ch;
vector<ll> pot,h;

void srt(ll x, ll le){
	if(x>=(1ll<<(n-1)))h[x]=s[x-1];
	else{
		srt(2*x,le/2);
		srt(2*x+1,le/2);
		ll l=2*x,r=2*x+1;
		if(h[l]>h[r])swap(l,r);
		h[x]=(pot[2*le]*s[x-1]+pot[le]*h[l]+h[r])%MOD;
	}
}

int main(){FIN;
	cin>>n;
	cin>>s;
	ch.resize(1ll<<n);
	fore(i,1,(1ll<<n)){
		if(i>=(1ll<<(n-1)))ch[i]={0,0};
		else ch[i]={2*i,2*i+1};
	}
	pot.pb(1);
	fore(i,1,(1ll<<n))pot.pb(pot.back()*P%MOD);
	h.resize(1ll<<n);
	srt(1,(1ll<<(n-1))-1);
	ll res=1;
	fore(i,1,(1ll<<(n-1))){
		if(h[2*i]!=h[2*i+1])res=(res+res)%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}