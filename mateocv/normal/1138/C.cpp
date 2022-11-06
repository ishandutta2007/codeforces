#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
		}
	}
	ll redh[n][m],redv[n][m];
	fore(i,0,n){
		vector<pair<ll,ll> > v;
		fore(j,0,m){
			v.pb({a[i][j],j});
		}
		sort(ALL(v));
		fore(j,0,m){
			if(j==0){
				redh[i][v[j].snd]=1;
			}else{
				redh[i][v[j].snd]=redh[i][v[j-1].snd]+(v[j].fst!=v[j-1].fst);
			}
		}
		
	}
	fore(j,0,m){
		vector<pair<ll,ll> > v;
		fore(i,0,n){
			v.pb({a[i][j],i});
		}
		sort(ALL(v));
		fore(i,0,n){
			if(i==0){
				redv[v[i].snd][j]=1;
			}else{
				redv[v[i].snd][j]=redv[v[i-1].snd][j]+(v[i].fst!=v[i-1].fst);
			}
		}
		
	}
	ll maxh[n],maxv[m];
	memset(maxh,0,sizeof maxh);
	memset(maxv,0,sizeof maxv);
	fore(i,0,n){
		fore(j,0,m){
			maxh[i]=max(maxh[i],redh[i][j]);
		}
	}
	fore(j,0,m){
		fore(i,0,n){
			maxv[j]=max(maxv[j],redv[i][j]);
		}
	}
	ll res[n][m];
	fore(i,0,n){
		fore(j,0,m){
			//ll lar=max(maxv[j],maxh[i]),cor=min(maxv[j],maxh[i]);
			res[i][j]=max(maxv[j]+max(0,redh[i][j]-redv[i][j]),maxh[i]+max(0,redv[i][j]-redh[i][j]));
		}
	}
	
	/*fore(i,0,n){
		fore(j,0,m){
			cout<<redh[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	fore(i,0,n){
		fore(j,0,m){
			cout<<redv[i][j]<<" ";
		}
		cout<<"\n";
	}*/
//	fore(i,0,n)cout<<maxh[i]<<" "; cout<<"\n";
//	fore(j,0,m)cout<<maxv[j]<<" "; cout<<"\n";
	
	fore(i,0,n){
		fore(j,0,m){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}