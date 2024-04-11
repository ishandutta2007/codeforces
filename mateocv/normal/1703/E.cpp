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

const int MAXN=110;

ll vis[MAXN][MAXN];
char a[MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			fore(j,0,n){
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		ll res=0;
		fore(i,0,n){
			fore(j,0,n){
				ll x=i,y=j;
				if(vis[x][y])continue;
				ll tot=0,s=0;
				while(1){
					//cout<<x<<" "<<y<<endl;
					vis[x][y]=1;
					tot++;
					s+=a[x][y]-'0';
					auto nx=y,ny=n-1-x;
					if(nx==i&&ny==j)break;
					x=nx; y=ny;
				}
				res+=min(s,tot-s);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}