#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[100005];

int main(){FIN;
	ll n; cin>>n;
	ll pa[n];
	pa[0]=-1;
	fore(i,1,n){
		cin>>pa[i]; pa[i]--;
		g[pa[i]].pb(i);
	}
	
	ll s[n];
	fore(i,0,n){
		cin>>s[i];
	}
	
	ll res=0,ok=0,a[n];
	fore(i,0,n){
		if(s[i]!=-1&&i!=0){
			if(s[i]-s[pa[pa[i]]]-a[pa[i]]>=0){
				a[i]=s[i]-s[pa[pa[i]]]-a[pa[i]];
			}else{
				ok++; break;
			}
			
		}else if(i==0){
			a[i]=s[i];
		}else{
			a[i]=1ll*1e18;
			if(SZ(g[i])==0){
				a[i]=0;
			}else{
				for(auto j:g[i]){
					if(s[j]>=s[pa[i]]){
						a[i]=min(a[i],s[j]-s[pa[i]]);
					}else{
						ok++; break;
					}
				}
				if(ok)break;	
			}
		}
	}
	
	fore(i,0,n){
		res+=a[i];
	//	cout<<a[i]<<" ";
	}
	//cout<<"\n";
	if(!ok){
		cout<<res;
	}else{
		cout<<-1;
	}
	
	return 0;
}