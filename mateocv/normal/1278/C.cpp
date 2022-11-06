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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		reverse(a,a+n);
		ll s=0;
		fore(i,0,n){
			if(a[i]==2)a[i]=-1;
			if(b[i]==2)b[i]=-1;
			s+=a[i],s+=b[i];
		}
		//fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";
		//fore(i,0,n)cout<<b[i]<<" "; cout<<"\n";
		//set<ll> st;
		ll sump=0;
		//st.insert(sump);
		map<ll,ll> u;
		u[0]=0;
		fore(i,0,n){
			sump+=b[i];
			//st.insert(sump);
			if(!u.count(sump)){
				u[sump]=i+1;
			}
		}
		ll res=2*n;
		if(u.count(s)){
			res=min(res,u[s]);
		}
		fore(i,0,n){
			s-=a[i];
			if(u.count(s)){
				res=min(res,i+1+u[s]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}