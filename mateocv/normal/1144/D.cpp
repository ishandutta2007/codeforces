#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	map<ll,ll>m;
	fore(i,0,n){
		cin>>a[i];
		if(!m.count(a[i])){
			m[a[i]]=1;
		}else{
			m[a[i]]++;
		}
	}
	ll maxi=-1,maxn=-1;
	for(auto i:m){
		if(i.snd>maxi){
			maxi=i.snd;
			maxn=i.fst;
		}
	}
	ll p=-1;
	fore(i,0,n){
		if(a[i]==maxn){
			p=i; break;
		}
	}
	cout<<n-maxi<<"\n";
	for(ll i=p-1;i>=0;i--){
		if(a[i]!=maxn){
			cout<<1+(a[i]>maxn)<<" "<<i+1<<" "<<i+2<<"\n";
		}
	}
	fore(i,p+1,n){
		if(a[i]!=maxn){
			cout<<1+(a[i]>maxn)<<" "<<i+1<<" "<<i<<"\n";
		}
	}	
	
	return 0;
}