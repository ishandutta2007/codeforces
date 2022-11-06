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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll pre[n],suf[n];
		mset(pre,0);
		mset(suf,0);
		fore(i,0,n-1){
			pre[i+1]=pre[i]+abs(a[i+1]-a[i]);
		}
		reverse(a,a+n);
		fore(i,0,n-1){
			suf[i+1]=suf[i]+abs(a[i+1]-a[i]);
		}
		reverse(a,a+n);
		reverse(suf,suf+n);
		//fore(i,0,n)cout<<pre[i]<<" "; cout<<"\n";
		//fore(i,0,n)cout<<suf[i]<<" "; cout<<"\n";
		ll res=min({pre[n-1],pre[n-2],suf[1]});
		fore(i,0,n-2)res=min(res,pre[i]+suf[i+2]+abs(a[i]-a[i+2]));
		cout<<res<<"\n";
	}
	
	return 0;
}