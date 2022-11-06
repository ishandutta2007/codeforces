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

map<ll,ll>mp;

int main(){FIN;
	ll n,p,k; cin>>n>>p>>k;
	ll a;
	fore(i,0,n){
		cin>>a;
		mp[((((a*a)%p)*((a*a)%p))%p-(k*a)%p+p)%p]++;
	}
	ll res=0;
	for(auto i:mp){
		//cout<<i.snd<<"\n";
		res+=(i.snd*(i.snd-1))/2;
	}
	cout<<res;
	return 0;
}