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
	ll n,m,k; cin>>n>>m>>k;
	ll a[m];
	fore(i,0,m)cin>>a[i];
	ll d[m];
	d[0]=a[0];
	fore(i,0,m-1){
		d[i+1]=a[i+1]-a[i];
	}
	ll va=k;
	ll res=0;
	ll i=0;
	while(i<m){
		ll s=0;
		while(i<m&&a[i]<=va){
			i++; s++;
		}
		if(s!=0)res++;
		va+=s;
		if(s==0){
			va+=((a[i]-va+k-1)/k)*k;
		}
		//cout<<i<<" "<<s<<" "<<va<<"\n";
	}
	cout<<res;
	return 0;
}