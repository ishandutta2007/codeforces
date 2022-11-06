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

const int MAXN=100005;

vector<ll> g[MAXN];

ll van[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n],b[n],c[m];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		fore(i,0,m)cin>>c[i],c[i]--;
		ll br=0,ul=-1;
		fore(i,0,n){
			if(b[n-1-i]==c[m-1]){
				br++; ul=n-1-i;
				break;
			}
		}
		if(!br){
			cout<<"NO\n";
			continue;
		}
		ll cb[n],cc[n];
		mset(cb,0); mset(cc,0);
		fore(i,0,n){
			if(a[i]!=b[i])cb[b[i]]++;
		}
		if(cb[c[m-1]]){
			fore(i,0,n){
				if(b[n-1-i]==c[m-1]&&a[n-1-i]!=b[n-1-i]){
					ul=n-1-i;
					break;
				}
			}
		}
		fore(i,0,m)cc[c[i]]++;
		br=0;
		fore(i,0,n){
			if(cc[i]<cb[i]){
				br++; break;
			}
		}
		if(br){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			fore(i,0,n)g[i].clear(),van[i]=0;
			fore(i,0,n){
				if(a[i]!=b[i])g[b[i]].pb(i);
			}
			fore(i,0,m){
				if(cb[c[i]]==0)cout<<ul+1<<" ";
				else if(van[c[i]]<SZ(g[c[i]])){
					cout<<g[c[i]][van[c[i]]]+1<<" ";
				}else{
					cout<<g[c[i]].back()+1<<" ";
				}
				van[c[i]]++;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}