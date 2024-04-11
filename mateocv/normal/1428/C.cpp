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

string s;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		ll res=0;
		for(auto i:s){
			if(i=='A'){
				res++;
			}else{
				if(res>0){
					res--;
				}else{
					res++;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}