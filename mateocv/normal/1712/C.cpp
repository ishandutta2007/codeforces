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

vector<ll> oc[100005];

ll vis[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+1)oc[i].clear(),vis[i]=0;
		fore(i,0,n)oc[a[i]].pb(i);
		ll ul=0,res=0;
		fore(i,0,n-1){
			if(a[i]>a[i+1]){
				fore(j,ul,i+1){
					if(a[j]!=0&&!vis[a[j]]){
						res++;
						for(auto jj:oc[a[j]])a[jj]=0;
						vis[a[j]]=1;
					}
				}
				ul=i+1;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}