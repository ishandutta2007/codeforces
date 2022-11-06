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
	ll n; cin>>n;
	pair<ll,ll> a[n];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n)a[i].fst*=2,a[i].snd*=2;
	if(n%2){
		cout<<"NO\n"; return 0;
	}
	ll x=(a[0].fst+a[n/2].fst)/2,y=(a[0].snd+a[n/2].snd)/2;
	fore(i,0,n/2){
		if(x!=(a[i].fst+a[n/2+i].fst)/2||y!=(a[i].snd+a[n/2+i].snd)/2){
			cout<<"NO\n"; return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}