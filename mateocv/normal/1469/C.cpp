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
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll d[n-1];
		fore(i,0,n-1){
			d[i]=a[i+1]-a[i];
		}
		//fore(i,0,n-1)cout<<d[i]<<" "; cout<<"\n";
		ll br=0;
		fore(i,0,n-2){
			ll c=k-1;
			if(d[i]<=-k){
				c=-k+1-d[i];
				if(c>=k){
					br++; break;
				}
				if(d[i+1]-c>-k){
					c=min(d[i+1]+k-1,k-1);
				}
			}else if(d[i]>=k){
				br++; break;
			}else{
				c=0;
				if(d[i+1]-c>-k){
					c=min({d[i+1]+k-1,k-1,k-1-d[i]});
				}
			}
			//cout<<c<<":\n";
			d[i]+=c; d[i+1]-=c;
			//fore(i,0,n-1)cout<<d[i]<<" "; cout<<"\n";
		}
		if(br){
			cout<<"No\n";
			continue;
		}
		fore(i,0,n-1){
			if(abs(d[i])>=k){
				br++; break;
			}
		}
		if(br){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
	}
	
	return 0;
}