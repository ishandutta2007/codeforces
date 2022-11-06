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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> x(n),y(n);
		fore(i,0,n)cin>>x[i];
		fore(i,0,n)cin>>y[i];
		vector<ll> v[2];
		fore(i,0,n)v[(y[i]-x[i]>=0)].pb(y[i]-x[i]);
		fore(k,0,2)sort(ALL(v[k]));
		reverse(ALL(v[1]));
		//for(auto i:v[0])cout<<i<<" "; cout<<"\n";
		//for(auto i:v[1])cout<<i<<" "; cout<<"\n";
		ll res=0;
		ll ul=0,pos=0;
		fore(i,0,SZ(v[1])){
			while(ul<SZ(v[0])&&v[0][ul]+v[1][i]<0)ul++;
			if(ul==SZ(v[0])){
				break;
			}
			res++;
			ul++;
			pos=i+1;
		}
		res+=(SZ(v[1])-pos)/2;
		cout<<res<<"\n";
	}
	
	return 0;
}