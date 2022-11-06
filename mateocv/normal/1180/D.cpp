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

int main(){FIN;
	ll n,m; cin>>n>>m;
	pair<ll,ll> a[n][m];
	fore(i,0,n){
		fore(j,0,m){
			a[i][j]={i+1,j+1};
		}
	}
	fore(i,0,n/2){
		fore(j,0,m){
			cout<<a[i][j].fst<<" "<<a[i][j].snd<<"\n";
			cout<<a[n-1-i][m-1-j].fst<<" "<<a[n-1-i][m-1-j].snd<<"\n";
		}
	}
	if(n%2){
		ll i=n/2;
		fore(j,0,m/2){
			cout<<a[i][j].fst<<" "<<a[i][j].snd<<"\n";
			cout<<a[n-1-i][m-1-j].fst<<" "<<a[n-1-i][m-1-j].snd<<"\n";
		}
		if(m%2){
			ll j=m/2;
			cout<<a[i][j].fst<<" "<<a[i][j].snd<<"\n";
		}
	}
	return 0;
}