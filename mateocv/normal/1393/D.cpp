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

ll dp[4040][4040];

char t[4040][4040];
char c[2020][2020];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(t[x][y]=='.'){
		return r=0;
	}
	if(x==0||y==0){
		return r=1;
	}
	if(t[x-1][y-1]!=t[x][y]){
		return r=1;
	}
	if(x<=1||y<=1||t[x][y-2]!=t[x][y]||t[x-2][y]!=t[x][y]){
		return 2;
	}
	r=min({f(x-1,y-1),f(x,y-2)+1,f(x-2,y)+1})+1;
	return r;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	mset(t,'.'); //ver
	fore(i,0,n){
		fore(j,0,m){
			t[i+j][2000+i-j]=c[i][j];
		}
	}
	mset(dp,-1);
	ll res=0;
	//cout<<"HOLAAAAA"<<endl;
	fore(i,0,4040){
		fore(j,0,4040){
			ll s=f(i,j);
			/*if(t[i][j]!='.'){
				cout<<i<<" "<<j<<": "<<s<<"\n";
			}*/
			res+=((s+1)>>1);
		}
	}
	cout<<res<<"\n";
	return 0;
}