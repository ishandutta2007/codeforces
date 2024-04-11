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

ll up(ll n){
	if(n>0){
		return (n+1)/2;
	}else{
		return n/2;
	}
}

ll down(ll n){
	if(n>0){
		return (n)/2;
	}else{
		return (n-1)/2;
	}
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll va=0;
	fore(i,0,n){
		if(a[i]&1){
			if(va%2==0){
				cout<<up(a[i])<<"\n";
			}else{
				cout<<down(a[i])<<"\n";
			}
			va++;
		}else{
			cout<<a[i]/2<<"\n";
		}
	}
	
	return 0;
}