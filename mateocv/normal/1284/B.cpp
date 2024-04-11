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

int main(){FIN;
	ll n; cin>>n;
	vector<vector<ll>> v;
	fore(i,0,n){
		ll l; cin>>l;
		vector<ll> vv;
		fore(i,0,l){
			ll lle; cin>>lle;
			vv.pb(lle);
		}
		v.pb(vv);
	}
	pair<ll,ll> p[n];
	//vector<ll> ex[2];
	ll c=0;
	fore(i,0,SZ(v)){
		ll br=0;
		fore(j,0,SZ(v[i])-1){
			if(v[i][j]<v[i][j+1]){
				br++; break;
			}
		}
		if(!br){
			p[c]={*min_element(ALL(v[i])),*max_element(ALL(v[i]))};
			//ex[0].pb(min_element(ALL(v[i])));
			//ex[1].pb(max_element(ALL(v[i])));
			c++;
		}
	}
	ll res=n*n;
	sort(p,p+c);
	//fore(i,0,c)cout<<p[i].fst<<" "<<p[i].snd<<"\n";
	fore(i,0,c){
		auto it=lower_bound(p,p+c,make_pair(p[i].snd,p[i].snd));
		//cout<<res<<" ";
		res-=c-(it-p);
		//cout<<res<<"\n";
	}
	cout<<res;
	
	return 0;
}