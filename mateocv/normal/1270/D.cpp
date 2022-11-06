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

ll k;

ll ask(ll i){
	cout<<"? ";
	fore(j,0,k+1){
		if(i!=j)cout<<j+1<<" ";
	}
	cout<<endl;
	ll resp,bs; cin>>bs;
	if(bs==-1)exit(0);
	cin>>resp;
	return resp;
}

map<ll,ll> m;

int main(){FIN;
	ll n; cin>>n>>k;
	fore(i,0,k+1){
		m[ask(i)]++;
	}
	assert(SZ(m)==2);
	cout<<"! "<<k+1-(m.begin()->snd)<<endl;
	return 0;
}