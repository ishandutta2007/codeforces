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
		string s,ss; cin>>s>>ss;
		ll l=0,r=0;
		while(l<SZ(s)&&r<SZ(ss)){
			if(s[l]==ss[r]){
				l++; r++;
			}else{
				l+=2;
			}
		}
		if(r==SZ(ss)&&(SZ(s)-l)%2==0){
			cout<<"YES\n";
			continue;
		}
		l=1,r=0;
		while(l<SZ(s)&&r<SZ(ss)){
			if(s[l]==ss[r]){
				l++; r++;
			}else{
				l+=2;
			}
		}
		if(r==SZ(ss)&&(SZ(s)-l)%2==0){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	
	return 0;
}