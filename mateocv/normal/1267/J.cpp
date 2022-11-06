#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

ll c[2000006];
int main() {FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll lle;
		set<ll>st;
		fore(i,0,n){
			cin>>lle;c[lle]++;
			st.insert(lle);
		}
		vector<ll> v;
		for(auto i:st)v.pb(c[i]);
		sort(ALL(v));
		ll res=1e18,resp=0;
		fore(s,2,v[0]+2){
			ll br=0;
			resp=0;
			for(auto i:v){
				ll r=(((-i)%s)+s)%s;
				if(i-r*(s-1)<0){br++; break;}
				resp+=(i-r*(s-1))/s+r;
			}
			if(br)continue;
			res=min(res,resp);
		}
		cout<<res<<"\n";
		for(auto i:st)c[i]=0;
	}
}