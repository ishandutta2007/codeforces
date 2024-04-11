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
		vector<ll> a(n+2);
		fore(i,0,n+2)cin>>a[i];
		set<ll> st,ss;
		ll s=0;
		fore(i,0,n+2){
			if(st.count(a[i]))ss.insert(a[i]);
			else st.insert(a[i]);
			s+=a[i];
		}
		vector<ll> r;
		fore(i,0,n+2){
			if((s-a[i])%2==0){
				ll sr=(s-a[i])/2;
				if(a[i]!=sr){
					if(st.count(sr)){
						r={sr,a[i]}; break;
					}
				}else{
					if(ss.count(sr)){
						r={sr,a[i]}; break;
					}
				}
			}
		}
		if(SZ(r)==0){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,n+2){
			if(r[0]==a[i]){
				r[0]=-1;
			}else if(r[1]==a[i]){
				r[1]=-1;
			}else{
				cout<<a[i]<<" ";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}