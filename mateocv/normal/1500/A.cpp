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

vector<ll> oc[2500006];

vector<pair<ll,ll>> occ[5000006];

void check(ll pos){
	fore(i,0,SZ(occ[pos])){
		fore(j,i+1,SZ(occ[pos])){
			vector<ll> v;
			v.pb(occ[pos][i].fst);
			v.pb(occ[pos][j].fst);
			v.pb(occ[pos][i].snd);
			v.pb(occ[pos][j].snd);
			sort(ALL(v));
			ll br=0;
			fore(i,0,SZ(v)-1){
				if(v[i]==v[i+1]){
					br++; break;
				}
			}
			if(!br){
				cout<<"YES\n";
				cout<<occ[pos][i].fst+1<<" "<<occ[pos][i].snd+1<<" ";
				cout<<occ[pos][j].fst+1<<" "<<occ[pos][j].snd+1<<" ";
				cout<<"\n";
				exit(0);
			}
		}
	}
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i],oc[a[i]].pb(i);
	ll ul=-1;
	fore(i,0,2500006){
		if(SZ(oc[i])>=4){
			cout<<"YES\n";
			fore(j,0,4)cout<<oc[i][j]+1<<" ";
			cout<<"\n";
			return 0;
		}
		if(SZ(oc[i])>=2){
			if(ul==-1)ul=i;
			else{
				cout<<"YES\n";
				cout<<oc[ul][0]+1<<" "<<oc[i][0]+1<<" ";
				cout<<oc[ul][1]+1<<" "<<oc[i][1]+1<<" ";
				cout<<"\n";
				return 0;
			}
		}
	}
	fore(i,0,n){
		fore(j,i+1,n){
			ll s=a[i]+a[j];
			occ[s].pb({i,j});
			if(SZ(occ[s])>=2){
				check(s);
			}
		}
	}
	cout<<"NO\n";
	
	return 0;
}