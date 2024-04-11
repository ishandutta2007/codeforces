#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;

vector<ll> v;

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll np[505];

ll pre[505][505];

ll pos[505][505];

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		string s,t; cin>>s>>t;
		v.clear();
		fore(i,0,SZ(s)-SZ(t)+1){
			if(t==s.substr(i,SZ(t)))v.pb(i);
		}
		ll mini=0,ul=0;
		fore(i,0,SZ(v)){
			if((i+1==SZ(v)&&ul<SZ(v))||(max(i+1,ul)<SZ(v)&&v[i+1]>=v[ul]+SZ(t))){
				mini++;
				while(ul<SZ(v)&&abs(v[ul]-v[i])<SZ(t))ul++;
			}
		}
		cout<<mini<<" ";
		fore(i,0,SZ(v)){
			np[i]=lower_bound(ALL(v),v[i]+SZ(t))-v.begin();
		}
		for(ll x=SZ(v);x>=0;x--){
			fore(y,0,SZ(v)+1){
				fore(z,0,mini+1){
					auto &res=pos[y][z];
					if(x==SZ(v)){
						res=(SZ(v)==y&&z==0);
					}else{
						res=pre[y][z];
						if(z&&x>=y&&abs(v[x]-v[y])<SZ(t))res=add(res,pre[np[x]][z-1]);
					}
				}
			}
			swap(pre,pos);
		}
		cout<<pre[0][mini]<<"\n";
	}
	
	return 0;
}