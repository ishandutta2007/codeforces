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

ll ask(ll x){
	cout<<"? "<<x+1<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

ll val=413;

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,val)ask(0);
	ll pos=-1;
	ll b=max(min(val-1,n/2-10),1ll);
	fore(i,0,(n-1)/b+1){
		if(ask(i*b)>k){
			pos=i*b;
			break;
		}
	}
	assert(pos!=-1);
	//cerr<<"Encontre la pos "<<pos<<endl;
	ll l=0,r=n/2;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask((pos-m+n)%n)>k)l=m+1;
		else r=m-1;
	}
	cout<<"! "<<(pos-l+n)%n+1<<endl;
	
	return 0;
}