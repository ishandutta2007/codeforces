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
		ll p[n];
		fore(i,0,n)cin>>p[i];
		vector<ll> v;
		ll va=-1,van=0;
		fore(i,0,n){
			if(p[i]==va)van++;
			else{
				if(va!=-1)v.pb(van);
				va=p[i];
				van=1;
			}
			if(i==n-1)v.pb(van);
		}
		//for(auto i:v)cout<<i<<" "; cout<<"\n";
		ll sum=0;
		for(auto i:v)sum+=i;
		ll g=0,s=0,b=0;
		g=v[0];
		ll ult=-1;
		fore(i,1,SZ(v)){
			if(s<=g)s+=v[i];
			else{
				ult=i;
				break;
			}
		}
		if(s<=g||ult==-1){
			cout<<"0 0 0\n"; continue;
		}
		fore(i,ult,SZ(v)){
			if(g+s+b+v[i]<=sum/2)b+=v[i];
			else break;
		}
		//cout<<g<<" "<<s<<" "<<b<<" NO\n";
		if(b<=g||b+s+g>sum/2){
			cout<<"0 0 0\n"; continue;
		}
		cout<<g<<" "<<s<<" "<<b<<"\n";
	}
	
	return 0;
}