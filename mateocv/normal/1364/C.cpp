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
	ll a[n+1];
	fore(i,0,n)cin>>a[i];
	a[n]=n+1;
	set<ll> st;
	fore(i,0,n+1)st.insert(i);
	ll res[n+1];
	mset(res,-1);
	fore(i,0,n){
		if(a[i]!=a[i+1]){
			res[i+1]=a[i];
			st.erase(a[i]);
		}
	}
	fore(i,0,n){
		if(res[i]==-1){
			ll b=*st.begin();
			res[i]=b;
			st.erase(b);
		}
	}
	fore(i,0,n)cout<<res[i]<<" "; cout<<"\n";
	
	return 0;
}