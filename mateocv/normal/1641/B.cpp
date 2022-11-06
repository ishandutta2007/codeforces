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

vector<pair<ll,ll>> ag;

vector<ll> s;

bool ch(vector<ll> a){
	sort(ALL(a));
	fore(i,0,SZ(a)){
		if(i%2==0&&(i+1>=SZ(a)||a[i+1]!=a[i]))return 0;
	}
	return 1;
}

ll n;

void rev(ll k){
	if(k<=0)return;
	fore(i,0,k)ag.pb({n-k+i,a[n-1-i]});
	s.pb(k);
	reverse(a.end()-k,a.end());
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		if(!ch(a)){
			cout<<"-1\n";
			continue;
		}
		ag.clear();
		s.clear();
		ll pos=-1;
		fore(i,0,n){
			if(i&1)continue;
			fore(j,i+1,n){
				if(a[i]==a[j]){
					pos=j;
					break;
				}
			}
			rev(n-pos);
			rev(n-i-1);
		}
		fore(i,0,n/2)s.pb(1);
		cout<<SZ(ag)<<"\n";
		for(auto i:ag)cout<<i.fst<<" "<<i.snd<<"\n";
		reverse(ALL(s));
		cout<<SZ(s)<<"\n";
		for(auto i:s)cout<<2ll*i<<" ";
		cout<<"\n";
	}
	
	return 0;
}