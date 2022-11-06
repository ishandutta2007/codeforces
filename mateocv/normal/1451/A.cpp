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

ll mind(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return i;
	}
	return n;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==1){
			cout<<"0\n";
		}else if(n==2){
			cout<<"1\n";
		}else if(n%2==0||n==3){
			cout<<"2\n";
		}else{
			cout<<"3\n";
		}
	}
	
	return 0;
}