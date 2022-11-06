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
	ll n,m,r; cin>>n>>m>>r;
	ll a=2000,b=0,l;
	fore(i,0,n){
		cin>>l;
		a=min(l,a);
	}
	fore(i,0,m){
		cin>>l;
		b=max(l,b);
	}
	cout<<max(r,r-(r/a)*a+(r/a)*b);
	return 0;
}