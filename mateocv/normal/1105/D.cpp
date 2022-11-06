#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

queue<pair<ll,ll>> q[10];
ll lar[10];
ll res[10];
//ll tot;

int main(){FIN;
	ll n,m,p; cin>>n>>m>>p;
	ll s[p];
	fore(i,0,p)cin>>s[i];
	char t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>t[i][j];
			if(t[i][j]>='0'&&t[i][j]<='9'){
				q[t[i][j]-'0'-1].push({i,j});
				lar[t[i][j]-'0'-1]++;
				//tot++;
			}
			//if(t[i][j]=='#')tot++;
		}
	}
	ll ya=0;
	while(ya<p){
		fore(i,0,p){
			if(lar[i]){
				fore(j,0,s[i]){
					while(lar[i]){
						pair<ll,ll> f=q[i].front(); q[i].pop();
						if(f.fst>0&&t[f.fst-1][f.snd]=='.')/*tot++,*/t[f.fst-1][f.snd]=(char)('1'+i),q[i].push({f.fst-1,f.snd});
						if(f.fst<n-1&&t[f.fst+1][f.snd]=='.')/*tot++,*/t[f.fst+1][f.snd]=(char)('1'+i),q[i].push({f.fst+1,f.snd});
						if(f.snd>0&&t[f.fst][f.snd-1]=='.')/*tot++,*/t[f.fst][f.snd-1]=(char)('1'+i),q[i].push({f.fst,f.snd-1});
						if(f.snd<m-1&&t[f.fst][f.snd+1]=='.')/*tot++,*/t[f.fst][f.snd+1]=(char)('1'+i),q[i].push({f.fst,f.snd+1});
						lar[i]--;
					}
					lar[i]=SZ(q[i]);
					if(lar[i]==0){ya++;break;}
				}
			}
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]>='0'&&t[i][j]<='9'){
				res[t[i][j]-'0'-1]++;
			}
		}
	}
	fore(i,0,p)cout<<res[i]<<" ";
	
	return 0;
}