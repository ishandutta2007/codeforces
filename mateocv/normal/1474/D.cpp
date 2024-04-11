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

const int MAXN=200005;

ll INF=2e18;

ll mini[2][2][MAXN];

ll a[MAXN],sump[MAXN];

ll db=0;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		sump[0]=a[0];
		fore(i,1,n){
			sump[i]=a[i]-sump[i-1];
		}
		if(db)fore(i,0,n)cout<<sump[i]<<" ";
		if(db)cout<<"\n";
		fore(i,0,2)fore(j,0,2)fore(ii,0,n+1)mini[i][j][ii]=INF;
		fore(k,0,2){
			fore(i,0,n){
				if((i+1)&1){
					mini[k][1][i+1]=min(mini[k][1][i],sump[i]);
					mini[k][0][i+1]=mini[k][0][i];
				}else{
					mini[k][0][i+1]=min(mini[k][0][i],sump[i]);
					mini[k][1][i+1]=mini[k][1][i];
				}
			}
			reverse(sump,sump+n);
		}
		if(db){
			fore(i,0,2){
				fore(j,0,2){
					cout<<i<<" "<<j<<":\n";
					fore(ii,0,n+1){
						cout<<mini[i][j][ii]<<" ";
					}
					cout<<"\n";
				}
			}
		}
		
		ll br=0;
		fore(i,0,n-1){
			if(db)cout<<i<<":\n";
			ll dif=(((n-i)&1)?2ll*(a[i+1]-a[i]):2ll*(a[i]-a[i+1]));
			if(sump[n-1]+dif!=0){
				continue;
			}
			if(db)cout<<dif<<" ";
			ll mint=INF;
			if(db)cout<<mini[0][0][i]<<" "<<mini[0][1][i]<<" ";
			mint=min({mint,mini[0][0][i],mini[0][1][i]});
			if(db)cout<<sump[i]-a[i]+a[i+1]<<" ";
			mint=min(mint,sump[i]-a[i]+a[i+1]);
			if(db)cout<<mini[1][0][n-(i+1)]-dif<<" "<<mini[1][1][n-(i+1)]+dif<<" ";
			mint=min({mint,mini[1][0][n-(i+1)]-dif,mini[1][1][n-(i+1)]+dif});
			if(db)cout<<"\n";
			if(mint>=0){
				br++; break;
			}
		}
		ll tot=0;
		fore(i,0,n)tot+=(sump[i]>=0);
		br+=(tot==n&&sump[n-1]==0);
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}