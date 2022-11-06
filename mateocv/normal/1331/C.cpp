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
	ll a[6];
	fore(i,0,6){
		a[i]=n%2;
		n/=2;
	}
	ll res=0;
	ll ord[6]={0,5,3,2,4,1};
	fore(i,0,6){
		res*=2;
		res+=a[5-ord[i]];
	}
	cout<<res;
	return 0;
}