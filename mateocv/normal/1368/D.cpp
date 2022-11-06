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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll b[20];
	mset(b,0);
	fore(i,0,n){
		fore(j,0,20){
			if(a[i]&(1ll<<j))b[j]++;
		}
	}
	ll res=0;
	fore(i,0,n){
		ll p=0;
		fore(j,0,20){
			if(b[j]>0)p+=(1ll<<j),b[j]--;
		}
		res+=p*p;
	}
	cout<<res;
	return 0;
}