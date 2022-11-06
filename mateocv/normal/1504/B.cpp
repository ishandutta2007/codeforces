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
		string a,b; cin>>a>>b;
		vector<ll> v={0};
		ll sum=0;
		fore(i,0,n){
			if(a[i]=='0')sum--;
			else sum++;
			if(sum==0)v.pb(i+1);
		}
		ll br=0;
		fore(i,0,SZ(v)-1){
			ll c[2]={0,0};
			fore(j,v[i],v[i+1]){
				c[a[j]==b[j]]++;
			}
			if(c[0]&&c[1])br++;
		}
		fore(j,v.back(),n){
			if(a[j]!=b[j])br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}