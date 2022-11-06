#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll compare(vector<ll> &v,vector<ll> &r){
	ll tot=0;
	fore(i,0,SZ(v)){
		if(v[i]>=r[i])tot++;	
	}
	if(tot==SZ(v))return 1;
	else return 0;
}
vector<ll> v[200005];

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	fore(i,0,26)v[0].pb(0);
	fore(i,1,SZ(s)+1){
		vector<ll> r=v[i-1];
		r[s[i-1]-'a']++;
		v[i]=r;
	}
	/*fore(i,0,SZ(s)+1){
		for(auto j:v[i])cout<<j<<" ";
		cout<<"\n";
	}*/
	ll m; cin>>m;
	while(m--){
		string t; cin>>t;
		vector<ll> hay(26);
		fore(i,0,SZ(t)){
			hay[t[i]-'a']++;
		}
		ll l=1,r=SZ(s)+1;
		while(l<=r) {
		  ll mid=(l+r)/2;
		  if(compare(v[mid],hay))r=mid-1;
		  else l=mid+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}