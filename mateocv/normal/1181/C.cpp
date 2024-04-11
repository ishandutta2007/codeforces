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
	ll n,m; cin>>n>>m;
	char t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>t[i][j];
		}
	}
	map<pair<pair<ll,ll>,pair<pair<ll,ll>,ll>>,ll> f[m];
	fore(j,0,m){
		vector<ll> v;
		char va=':'; ll van=0;
		fore(i,0,n){
			if(t[i][j]==va)van++;
			else{
				v.pb(van);
				van=1; va=t[i][j];
			}
			if(i==n-1){
				v.pb(van);	
			}
		}
		vector<ll>p;
		p.pb(0);
		fore(i,0,SZ(v))p.pb(p.back()+v[i]);
		fore(i,1,SZ(v)-1){
			if(v[i-1]>=v[i]&&v[i]<=v[i+1]){
				f[j][{{p[i]-v[i],p[i]+2*v[i]},{{t[p[i-1]][j],t[p[i]][j]},t[p[i+1]][j]}}]++; //cerrado abierto
			}
		}
	}
	//fore(j,0,m)cout<<SZ(f[j])<<" ";
	fore(j,0,m){
		for(auto i:f[j]){
			fore(jj,j+1,m){
				if(f[jj].count(i.fst)){
					f[jj].erase(i.fst);
					f[j][i.fst]++;
				}else{
					break;
				}
			}
		}
	}
	ll res=0;
	fore(j,0,m){
		for(auto i:f[j]){
			res+=(i.snd*(i.snd+1))/2;
		}
	}
	cout<<res;
	
	
	return 0;
}