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
		string s; cin>>s;
		ll st=-1;
		fore(i,0,n){
			if(s[i]!='?'){
				st=i;
				break;
			}
		}
		if(st==-1){
			st=0;
			s[0]='R';
		}
		fore(i,st+1,n){
			if(s[i]=='?'){
				s[i]=('R'^'B'^s[i-1]);
			}
		}
		reverse(ALL(s));
		st=-1;
		fore(i,0,n){
			if(s[i]!='?'){
				st=i;
				break;
			}
		}
		fore(i,st+1,n){
			if(s[i]=='?'){
				s[i]=('R'^'B'^s[i-1]);
			}
		}
		reverse(ALL(s));
		cout<<s<<"\n";
	}
	
	return 0;
}