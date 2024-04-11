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

ll esp(ll n){
	if(n==1)return 0;
	fore(i,2,n){
		if(n%i==0)return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll s=0;
		for(auto i:a)s+=i;
		if(!esp(s)){
			cout<<n<<"\n";
			fore(i,0,n)cout<<i+1<<" ";
			cout<<"\n";
		}
		else{
			cout<<n-1<<"\n";
			ll ya=0;
			fore(i,0,n){
				if((a[i]&1)&&!ya)ya++;
				else cout<<i+1<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}