#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll t[n];
	fore(i,0,n){
		cin>>t[i];
	}
	vector<ll> v;
	ll va=0, vat=0;
	fore(i,0,n){
		if(vat==t[i]){
			va++;
		}else{
			v.pb(va);
			va=1;
			vat=t[i];
		}
		if(i==n-1){
			v.pb(va);
		}
	}
	ll maxi=0;
	/*fore(i,0,SZ(v))cout<<v[i]<<" ";
	cout<<"\n";*/
	fore(i,1,SZ(v)){
		maxi=max(maxi,min(v[i],v[i-1]));
	}
	cout<<2*maxi;
	
	return 0;
}