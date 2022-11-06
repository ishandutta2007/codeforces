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

vector<ll> d;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll cont[2]={0,0};
		fore(i,0,n){
			cont[s[i]=='W']++;
		}
		if(cont[0]==n){
			if(k==0){
				cout<<"0\n";
			}else{
				cout<<2*min(k,n)-1<<"\n";
			}
			continue;
		}
		ll va=0,ya=0,cc=0;
		fore(i,0,n){
			if(!ya){
				ya+=(s[i]=='W');
			}else{
				if(s[i]=='L')va++;
				else{
					if(va!=0)d.pb(va);
					va=0;
				}
			}
			if((s[i]=='W')&&(i==0||s[i-1]!=s[i])){
				cc++;
			}
		}
		ll res=2ll*min(n,cont[1]+k);
		ll tot=0;
		sort(ALL(d));
		reverse(ALL(d));
		while(SZ(d)){
			if(d.back()<=k){
				tot++;
				k-=d.back();
				d.pop_back();
			}else{
				break;
			}
		}
		res-=cc-tot;
		cout<<res<<"\n";
		d.clear();
	}
	
	return 0;
}