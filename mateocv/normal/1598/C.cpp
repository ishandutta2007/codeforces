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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll s=0;
		fore(i,0,n){
			s+=a[i];
		}
		if((2ll*s)%n!=0){
			cout<<"0\n";
			continue;
		}
		ll sp=(2ll*s)/n;
		map<ll,ll> mp;
		for(auto i:a)mp[i]++;
		ll res=0;
		for(auto i:mp){
			if(i.fst<(sp+1)/2){
				res+=i.snd*mp[sp-i.fst];
			}
		}
		if(sp%2==0)res+=mp[sp/2]*(mp[sp/2]-1)/2;
		cout<<res<<"\n";
	}
	
	return 0;
}