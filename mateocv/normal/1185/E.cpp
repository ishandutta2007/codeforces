#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll tt; cin>>tt;
	while(tt--){
		ll n,m; cin>>n>>m;
		char t[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>t[i][j];
			}
		}
		char k='.';
		pair<ll,ll> ult;
		//ll llen[n][m];
		//mset(llen,0);
		vector<pair<ll,ll>> v[26];
		fore(i,0,n){
			fore(j,0,m){
				if(t[i][j]!='.'){
					//llen[i][j]++;
					if(k<t[i][j]){
						ult={i,j};
						k=t[i][j];
					}
					v[(int)(t[i][j]-'a')].pb({i,j});
				}
			}
		}
		//cout<<k<<"\n";
		//ll llenp[n+10][m+10];
		//mset(llenp,0);
		/*fore(i,1,n+1){
			fore(j,1,m+1){
				llenp[i][j]=llen[i-1][j-1]+llenp[i][j-1]+llenp[i-1][j]-llenp[i-1][j-1];
			}
		}*/
		/*fore(i,0,n+1){
			fore(j,0,m+1){
				cout<<llenp[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		if(k=='.'){
			cout<<"YES\n0\n"; continue;
		}
		ll kk=k-'a'+1;
		vector<pair<pair<ll,ll>,pair<ll,ll>>>res;
		ll br=0;
		fore(i,0,kk){
			if(SZ(v[i])==0){
				res.pb({ult,ult});
			}else{
				sort(ALL(v[i]));
				if(v[i][0].fst==v[i][SZ(v[i])-1].fst){
					ll tot=0;
					fore(j,0,SZ(v[i])){
						tot+=(v[i][j].fst==v[i][0].fst);
					}
					//cout<<tot<<"\n";
					fore(j,v[i][0].snd,v[i][SZ(v[i])-1].snd+1){
						tot+=(t[v[i][0].fst][j]>='a'+i);
					}
					//cout<<llenp[v[i][SZ(v[i])-1].fst+1][v[i][SZ(v[i])-1].snd+1]-llenp[v[i][SZ(v[i])-1].fst][v[i][SZ(v[i])-1].snd+1]-llenp[v[i][0].fst+1][v[i][0].snd]+llenp[v[i][0].fst][v[i][0].snd]<<" "<<v[i][SZ(v[i])-1].snd-v[i][0].snd+1;
					//&&llenp[v[i][SZ(v[i])-1].fst+1][v[i][SZ(v[i])-1].snd+1]-llenp[v[i][SZ(v[i])-1].fst][v[i][SZ(v[i])-1].snd+1]-llenp[v[i][0].fst+1][v[i][0].snd]+llenp[v[i][0].fst][v[i][0].snd]==v[i][SZ(v[i])-1].snd-v[i][0].snd+1
					//cout<<tot<<"\n";
					if(tot==SZ(v[i])-v[i][0].snd+v[i][SZ(v[i])-1].snd+1){
						res.pb({v[i][0],v[i][SZ(v[i])-1]}); continue;
					}
				}
				if(v[i][0].snd==v[i][SZ(v[i])-1].snd){
					ll tot=0;
					fore(j,0,SZ(v[i])){
						tot+=(v[i][j].snd==v[i][0].snd);
					}
					//cout<<tot<<"\n";
					fore(j,v[i][0].fst,v[i][SZ(v[i])-1].fst+1){
						tot+=(t[j][v[i][0].snd]>='a'+i);
					}
					//&&llenp[v[i][SZ(v[i])-1].fst+1][v[i][SZ(v[i])-1].snd+1]-llenp[v[i][SZ(v[i])-1].fst+1][v[i][SZ(v[i])-1].snd]-llenp[v[i][0].fst][v[i][0].snd+1]+llenp[v[i][0].fst][v[i][0].snd]==v[i][SZ(v[i])-1].fst-v[i][0].fst+1
					//cout<<tot<<"\n";
					if(tot==SZ(v[i])-v[i][0].fst+v[i][SZ(v[i])-1].fst+1){
						res.pb({v[i][0],v[i][SZ(v[i])-1]}); continue;
					}
				}
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		cout<<"YES\n"<<kk<<"\n";
		fore(i,0,SZ(res)){
			cout<<res[i].fst.fst+1<<" "<<res[i].fst.snd+1<<" "<<res[i].snd.fst+1<<" "<<res[i].snd.snd+1<<"\n";
		}
	}
	
	return 0;
}