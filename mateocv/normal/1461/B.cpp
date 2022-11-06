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

char c[550][550];

ll sump[550][550];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			fore(j,0,m)cin>>c[i][j];
		}
		ll res=0;
		fore(i,0,n){
			fore(j,0,m){
				sump[i][j+1]=sump[i][j]+(c[i][j]=='*');
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				fore(k,0,n){
					if(i+k>=n||j-k<0||j+k+1>m)break;
					if(sump[i+k][j+k+1]-sump[i+k][j-k]==2*k+1)res++;
					else break;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}