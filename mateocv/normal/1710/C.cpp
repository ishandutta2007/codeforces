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
typedef int ll;

const int MOD=998244353;

string s;

ll dp[200005][8][8];

inline void add(ll &x, ll &y){
	x+=y;
	if(x>=MOD)x-=MOD;
}

int main(){FIN;
	cin>>s;
	ll mk[8];
	fore(i,0,2){
		fore(j,0,2){
			fore(k,0,2){
				mk[4*i+2*j+k]=7-(4*(i^j)+2*(j^k)+(k^i));
			}
		}
	}
	mk[0]=0; mk[7]=0;
	//fore(i,0,8)cout<<mk[i]<<"\n";
	for(ll x=SZ(s);x>=0;x--){
		fore(y,0,8){
			fore(z,0,8){
				ll &res=dp[x][y][z];
				if(x==SZ(s))res=(z==7);
				else{
					fore(a,0,2){
						if(a>(s[x]-'0')+(y&1))continue;
						fore(b,0,2){
							if(b>(s[x]-'0')+!!(y&2))continue;
							fore(c,0,2){
								if(c>(s[x]-'0')+!!(y&4))continue;
								ll val=0;
								val=(val|((a<(s[x]-'0'))<<0));
								val=(val|((b<(s[x]-'0'))<<1));
								val=(val|((c<(s[x]-'0'))<<2));
								add(res,dp[x+1][y|val][z|mk[a+(b<<1)+(c<<2)]]);
							}
						}
					}
				}
				//cout<<x<<" "<<y<<" "<<z<<" : "<<res<<"\n";
			}
		}
	}
	cout<<dp[0][0][0]<<"\n";
	
	return 0;
}