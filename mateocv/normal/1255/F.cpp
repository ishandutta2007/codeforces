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

ll ask(ll t, ll i, ll j, ll k){
	cout<<t<<" "<<i<<" "<<j<<" "<<k<<endl;
	ll resp; cin>>resp;
	return resp;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v[2];
	fore(i,2,n){
		v[ask(2,1,2,i+1)==-1].pb({ask(1,1,2,i+1),i});
	}
	deque<ll> d[2];
	fore(k,0,2){
		sort(ALL(v[k]));
		reverse(ALL(v[k]));
		//for(auto i:v[k])cout<<i.snd<<" "; cout<<"\n";
		if(SZ(v[k]))d[k].pb(v[k][0].snd+1);
		fore(i,0,SZ(v[k])-1){
			if(ask(2,1+k,v[k][i].snd+1,v[k][i+1].snd+1)==1)d[k].push_front(v[k][i+1].snd+1);
			else d[k].pb(v[k][i+1].snd+1);
		}
	}
	vector<ll> res;
	for(auto i:d[0])res.pb(i);//,cout<<i<<" "; cout<<"\n";
	res.pb(2);
	for(auto i:d[1])res.pb(i);//,cout<<i<<" "; cout<<"\n";
	res.pb(1);
	reverse(ALL(res));
	cout<<0<<" ";
	for(auto i:res)cout<<i<<" ";
	return 0;
}