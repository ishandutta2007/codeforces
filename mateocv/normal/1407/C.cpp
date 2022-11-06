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

ll ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

int main(){FIN;
	ll n; cin>>n;
	set<ll> st;
	fore(i,0,n)st.insert(i+1);
	vector<ll> pos;
	fore(i,0,n)pos.pb(i);
	ll res[n];
	mset(res,-1);
	while(SZ(pos)>=2){
		ll a=ask(pos.back(),pos[SZ(pos)-2]);
		ll b=ask(pos[SZ(pos)-2],pos.back());
		if(a>b){
			res[pos.back()]=a;
			pos.pop_back();
			st.erase(a);
		}else{
			ll bb=pos.back();
			pos.pop_back();
			res[pos.back()]=b;
			pos.pop_back();
			pos.pb(bb);
			st.erase(b);
		}
	}
	res[pos.back()]=*st.begin();
	cout<<"! ";
	fore(i,0,n)cout<<res[i]<<" "; cout<<endl;
	
	return 0;
}