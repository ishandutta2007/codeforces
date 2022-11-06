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

vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0}};

ll n,m;

bool valid(ll x, ll y){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		ll br=0;
		fore(i,0,n){
			fore(j,0,m){
				if(s[i][j]=='.')continue;
				//cout<<i<<" "<<j<<":\n";
				set<pair<ll,ll>> ve={{i,j}};
				ll c=0,mk=0;
				fore(d,0,4){
					ll x=i+dir[d].fst,y=j+dir[d].snd;
					if(valid(x,y)&&s[x][y]=='*'){
						//cout<<"c++ "<<x<<" "<<y<<"\n";
						c++;
						mk|=(1ll<<d);
						ve.insert({x,y});
					}
				}
				if(c>=3||(c==2&&(mk==5||mk==10))){
					br++;
					//cout<<"f\n";
				}
				if(c==2){
					for(auto i:ve){
						fore(ii,-1,2){
							fore(jj,-1,2){
								ll x=i.fst+ii,y=i.snd+jj;
								if(valid(x,y)&&s[x][y]=='*'&&!ve.count({x,y})){
									br++;
									//cout<<"s\n"<<i.fst<<" "<<i.snd<<"\n";
									//cout<<x<<" "<<y<<"\n";
								}
							}
						}
					}
				}
				if(c==2&&!br){
					for(auto i:ve)s[i.fst][i.snd]='.';
				}
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				if(s[i][j]=='*')br++;
			}
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}