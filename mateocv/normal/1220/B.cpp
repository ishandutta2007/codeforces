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

/*ll raiz(ll n){
	fore(i,max(0ll,1ll*sqrt(n)-3),1ll*sqrt(n)+4){
		if(i*i==n)return i;
	}
}*/

int main(){FIN;
	ll n; cin>>n;
	ll a[n][n];
	fore(i,0,n){
		fore(j,0,n){
			cin>>a[i][j];
		}
	}
	ll a1=a[0][1]*a[0][2]/a[1][2];
	a1=sqrt(a1);
	cout<<a1<<" ";
	fore(i,1,n){
		cout<<a[0][i]/a1<<" ";
	}
	
	return 0;
}