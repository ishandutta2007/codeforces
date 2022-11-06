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

ll a[16];
ll isor(ll x,ll y){
	ll tot=0;
	fore(i,x,y-1){
		if(a[i]<=a[i+1])tot++;
	}
	return (tot==y-x-1);
}

int main(){FIN;
	ll n; cin>>n;
	/*fore(i,0,16){
		a[i]=5000-i;
	}*/
	fore(i,0,n)cin>>a[i];
	fore(i,0,log2(n)+1){
		fore(j,0,i+1){
			if(isor(j*n/(1<<i),(j+1)*n/(1<<i))){
				cout<<n/(1<<i); return 0;
			}
		}
	}
	
	return 0;
}