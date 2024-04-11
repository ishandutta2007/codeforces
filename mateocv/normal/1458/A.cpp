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

const int MAXN=200005;

ll a[MAXN],b[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(a,a+n);
	ll g=0;
	fore(i,0,n-1)g=__gcd(g,a[i+1]-a[i]);
	fore(i,0,m){
		cout<<__gcd(a[0]+b[i],g)<<" ";
	}
	cout<<"\n";
	
	return 0;
}