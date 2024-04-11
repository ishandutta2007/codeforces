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

ll sump[404][404];

ll get(ll x0, ll y0, ll x1, ll y1, bool b){
	ll res=sump[x1+1][y1+1]-sump[x1+1][y0]-sump[x0][y1+1]+sump[x0][y0];
	if(b)res=(x1-x0+1)*(y1-y0+1)-res;
	//cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<" "<<b<<" "<<res<<"\n";
	return res;
}

vector<string> s;

ll get1(ll x, ll y, ll b){
	ll res=s[x][y]-'0';
	if(b)res^=1;
	return res;
}

ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		s.clear();
		s.resize(n);
		fore(i,0,n)cin>>s[i];
		fore(i,0,n+1){
			fore(j,0,m+1){
				sump[i][j]=0;
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				sump[i+1][j+1]=sump[i+1][j]+sump[i][j+1]-sump[i][j]+(s[i][j]-'0');
			}
		}
		ll res=INF;
		fore(i,0,n){
			fore(ii,i+4,n){
				ll mini=INF;
				queue<ll> q;
				ll sumv=0;
				fore(j,0,m){
					if(j>=3){
						mini=min(mini,q.front());
						q.pop();
						res=min(res,sumv+get(i+1,j,ii-1,j,1)+mini);
					}
					sumv+=get(i+1,j,ii-1,j,0);
					sumv+=get1(i,j,1);
					sumv+=get1(ii,j,1);
					q.push(-sumv+get(i+1,j,ii-1,j,1));
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}