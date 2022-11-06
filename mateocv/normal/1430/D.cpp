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

vector<ll> disp;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		disp.clear();
		ll n; cin>>n;
		string s; cin>>s;
		fore(i,1,n){
			if(s[i]==s[i-1])disp.pb(i);
		}
		reverse(ALL(disp));
		reverse(ALL(s));
		ll res=0,va=0;
		while(SZ(s)){
			if(SZ(disp)){
				disp.pop_back();
				char c=s.back();
				res++;
				while(s.back()==c){
					if(va==disp.back())disp.pop_back();
					va++;
					s.pop_back();
				}
			}else{
				res++;
				char c=s.back();
				while(s.back()==c){
					s.pop_back();
				}
				if(SZ(s)){
					c=s.back();
					while(s.back()==c){
						s.pop_back();
					}	
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}