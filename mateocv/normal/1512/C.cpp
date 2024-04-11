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
		ll a,b; cin>>a>>b;
		string s; cin>>s;
		ll n=a+b;
		for(auto i:s){
			if(i=='0')a--;
			if(i=='1')b--;
		}
		if(min(a,b)<0){
			cout<<-1<<"\n";
			continue;
		}
		fore(i,0,n){
			if(s[i]=='?'&&s[n-1-i]!='?'){
				if(s[n-1-i]=='0'){
					a--; s[i]='0';
				}else{
					b--; s[i]='1';
				}
			}
		}
		if(min(a,b)<0){
			cout<<-1<<"\n";
			continue;
		}
		fore(i,0,n){
			if(s[i]=='?'&&i!=n-1-i){
				if(a>=2){
					a-=2;
					s[i]='0';
					s[n-1-i]='0';
				}else{
					b-=2;
					s[i]='1';
					s[n-1-i]='1';
				}
			}
		}
		if(min(a,b)<0){
			cout<<-1<<"\n";
			continue;
		}
		
		if(n/2==n-1-n/2&&s[n/2]=='?'){
			if(a>=1){
				s[n/2]='0';
				a--;
			}else{
				s[n/2]='1';
				b--;
			}
		}
		if(min(a,b)<0){
			cout<<-1<<"\n";
			continue;
		}
		string ss=s;
		reverse(ALL(ss));
		if(ss==s)cout<<s<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}