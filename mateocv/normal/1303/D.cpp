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

ll c[32];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		mset(c,0);
		ll a;
		fore(i,0,m){
			cin>>a;
			fore(j,0,30){
				if(a==(1<<j)){
					c[j]++; break;
				}
			}
		}
		ll tot=0;
		fore(i,0,30)tot+=(1ll<<i)*c[i];
		if(tot<n){
			cout<<-1<<"\n"; continue;
		}
		ll va=0,res=0;
		ll br=0;
		while(n>0){
			//cout<<va<<" ";
			if(c[va]>=n){
			//	cout<<va<<" ";
				cout<<res<<"\n"; br++; break;
			}
			if(n%2==0){
				c[va+1]+=c[va]/2;
				va++;
				n/=2;
			}else{
				if(c[va]==0){
					//cout<<"HOLA\n";
					fore(j,va+1,30){
						if(c[j]>=1){
							//cout<<"j "<<j<<"\n";
							c[j]--;
							fore(jj,va,j){
								res++;
								c[jj]++;
							}
							break;
						}
					}
					n--;
					c[va+1]+=c[va]/2;
					va++;
					n/=2;
				}else{
					n--;
					c[va]--;
					c[va+1]+=c[va]/2;
					va++;
					n/=2;
				}
			}
		}
		if(br)continue;
		cout<<res<<"\n";
	}
	
	return 0;
}