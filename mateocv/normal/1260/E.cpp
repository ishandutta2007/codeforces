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
	ll yo=-1;
	fore(i,0,n){
		if(a[i]==-1){
			yo=i;
		}
	}
	fore(i,0,yo+1){
		a[i]=0;
	}
	//STree st(n);
	//fore(i,0,n)st.upd(i,a[i]);
	ll res=0;
	for(ll i=20;i>=0;i--){
		if((1<<i)>n)continue;
		ll mini=1e18,minid=-1;
		fore(j,(1<<i)-1,n){
			if(a[j]<=mini){
				mini=a[j];
				minid=j;
			}
		}
		res+=mini;
		a[minid]=1e18;
	}
	cout<<res;
	return 0;
}