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

ll ask(ll l, ll r){
	cout<<"? "<<l+1<<" "<<r+1<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return r-l+1-resp;
}

int main(){FIN;
	ll n,t,k; cin>>n>>t>>k;
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask(0,m)>=k)r=m-1;
		else l=m+1;
	}
	cout<<"! "<<l+1<<"\n";
	
	return 0;
}