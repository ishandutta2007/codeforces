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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n){
			b[i]-=a[i];
		}
		/*ll tot=0;
		ll dif=0;
		ll cero=0;
		fore(i,0,n-1){
			if(a[i]==a[i+1])tot++;
			else dif++;
			if(a[i]==0)cero++;
		}
		if(a[n-1]==0)cero++;
		if(tot==n-1||(cero&&dif==2)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}*/
		vector<ll> v;
		set<ll> s;
		ll br=0;
		fore(i,0,n){
			if(b[i]!=0){
				v.pb(i);
				s.insert(b[i]);
			}
			if(b[i]<0){
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		fore(i,0,SZ(v)-1){
			if((v[i]+1)!=v[i+1]){
				cout<<"NO\n"; br++; break;
			}
		}
		if(br)continue;
		if(SZ(s)<=1){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	
	return 0;
}