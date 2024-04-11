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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ll> v[2];
		fore(i,0,n){
			if(a[i]>b[i]){
				fore(j,0,a[i]-b[i])v[0].pb(i);
			}else if(a[i]<b[i]){
				fore(j,0,b[i]-a[i])v[1].pb(i);
			}
		}
		if(SZ(v[0])!=SZ(v[1])){
			cout<<"-1\n";
		}else{
			cout<<SZ(v[0])<<"\n";
			fore(i,0,SZ(v[0]))cout<<v[0][i]+1<<" "<<v[1][i]+1<<"\n";
		}
	}
	
	return 0;
}