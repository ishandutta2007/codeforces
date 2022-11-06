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
		ll m,n; cin>>n>>m;
		ll a[n];
		ll b[m];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,m)cin>>b[i],b[i]--;
		ll u[n];
		fore(i,0,n)u[a[i]]=i;
		ll maxi=-1;
		ll res=0,van=0;
		fore(i,0,m){
			if(u[b[i]]<maxi)res++,van++;
			else{
				maxi=u[b[i]];
				res+=2*u[b[i]]+1-2*van;
				van++;
			}
			//cout<<" "<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}