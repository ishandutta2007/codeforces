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
	ll n,m,h; cin>>n>>m>>h;
	ll a[m],b[n];
	fore(i,0,m)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll c[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			c[i][j]*=min(a[j],b[i]);
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}