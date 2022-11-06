#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll getpos(ll n, ll pos){
	if(pos==n*(n-1)+1){
		return 0;
	}
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(n*(n-1)-(n-m-1)*(n-m-2)>=pos)r=m-1;
		else l=m+1;
	}
	if(pos%2)return l;
	else return (pos-(n*(n-1)-(n-l)*(n-l-1)))/2+l;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r;
		fore(i,l,r+1){
			cout<<getpos(n,i)+1<<" ";
			//getpos(n,i);
		}
		cout<<"\n";
	}
	
	return 0;
}