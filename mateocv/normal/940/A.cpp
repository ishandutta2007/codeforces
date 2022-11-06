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
	ll n,d; cin>>n>>d;
	ll x[n];
	fore(i,0,n)cin>>x[i];
	sort(x,x+n);
	ll res=200;
	fore(i,0,n){
		ll tot=0;
		fore(j,0,n){
			if(x[i]-x[j]>d||x[j]>x[i])tot++;
		}
		res=min(res,tot);
	}
	cout<<res;
	return 0;
}