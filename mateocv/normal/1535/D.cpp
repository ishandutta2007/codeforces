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

vector<ll> cant;
string s;
ll k;

void upd(ll pos){
	ll a=1,b=1;
	if(pos<(1ll<<(k-1))){
		a=cant[2*pos];
		b=cant[2*pos+1];
	}
	if(s[pos]=='?')cant[pos]=a+b;
	if(s[pos]=='0')cant[pos]=b;
	if(s[pos]=='1')cant[pos]=a;
}

int main(){FIN;
	cin>>k;
	cin>>s;
	s+='.';
	reverse(ALL(s));
	cant.clear();
	cant.resize(1ll<<k);
	for(ll i=(1<<k)-1;i>=1;i--){
		upd(i);
	}
	ll q; cin>>q;
	while(q--){
		ll pos; cin>>pos;
		char c; cin>>c;
		pos=(1ll<<k)-pos;
		s[pos]=c;
		ll va=pos;
		while(va){
			upd(va);
			va>>=1;
		}
		cout<<cant[1]<<"\n";
	}
	
	return 0;
}