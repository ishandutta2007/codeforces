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

const int MAXN = 200005;

ll a[MAXN];

ll cant[110];

vector<ll> g[2*MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cant[a[i]]++;
	ll maxi=-1,maxiv=-1,cantm=0;
	fore(i,0,100){
		if(cant[i]>maxi){
			maxi=cant[i];
			maxiv=i;
			cantm=1;
		}else if(cant[i]==maxi){
			cantm++;
		}
	}
	if(cantm>=2){
		cout<<n<<"\n";
		return 0;
	}
	//cout<<"Caso no trivial "<<maxi<<"\n";
	assert(maxiv!=-1);
	ll res=0;
	fore(i,0,100){
		if(i==maxiv)continue;
		ll sump=0;
		g[sump+MAXN].pb(0);
		fore(j,0,n){
			sump+=(a[j]==maxiv)-(a[j]==i);
			g[sump+MAXN].pb(j+1);
		}
		fore(j,0,2*MAXN){
			if(SZ(g[j])){
				res=max(res,g[j].back()-g[j][0]);
				g[j].clear();
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}