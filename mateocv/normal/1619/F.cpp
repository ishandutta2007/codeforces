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
		ll n,m,k; cin>>n>>m>>k;
		ll p=n/m;
		ll c=n%m;
		ll ul=0,st=0;
		fore(_,0,k){
			ul=st;
			fore(j,0,c){
				cout<<p+1<<" ";
				fore(i,0,p+1){
					ul=(ul+1)%n;
					cout<<ul+1<<" ";
				}
				cout<<"\n";
			}
			fore(j,0,m-c){
				cout<<p<<" ";
				fore(i,0,p){
					ul=(ul+1)%n;
					cout<<ul+1<<" ";
				}
				cout<<"\n";
			}
			st=(st+(p+1)*c)%n;
		}
		cout<<"\n";
	}
	
	return 0;
}