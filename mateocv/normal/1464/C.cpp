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

ll c[26];

int main(){FIN;
	ll n,t; cin>>n>>t;
	cin>>s;
	t-=(1ll<<(s[n-1]-'a'))-(1ll<<(s[n-2]-'a'));
	fore(k,0,2)s.pop_back();
	for(auto i:s)c[i-'a']++;
	t=abs(t);
	for(ll i=25;i>=0;i--){
		ll cant=t/(1ll<<i);
		if(c[i]<cant){
			t-=c[i]*(1ll<<i);
		}else{
			if(cant%2==c[i]%2){
				t-=cant*(1ll<<i);
			}else{
				t=min(t-(cant-1)*(1ll<<i),abs(t-(cant+1)*(1ll<<i)));
			}
		}
	}
	if(t==0)cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}