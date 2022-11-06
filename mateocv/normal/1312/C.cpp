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
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll tot=0;
		fore(i,0,n)tot+=(a[i]==0);
		if(tot==n){
			cout<<"YES\n"; continue;
		}
		vector<ll> p={1};
		while(p.back()*k<=10000000000000000)p.pb(p.back()*k);
		ll br=0;
		while(SZ(p)){
			ll maxid=-1,maxi=*max_element(a,a+n);
			fore(i,0,n)if(a[i]==maxi)maxid=i;
			while(SZ(p)&&p.back()>maxi){
				p.pop_back();
			}
			if(!SZ(p))break;
			a[maxid]-=p.back();
			p.pop_back();
		}
		//if(br)continue;
		fore(i,0,n){
			if(a[i]!=0){
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		cout<<"YES\n";
	}
	
	return 0;
}