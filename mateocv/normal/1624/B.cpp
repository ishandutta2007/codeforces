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
		ll a,b,c; cin>>a>>b>>c;
		ll br=0;
		if((b+b-a)%c==0&&(b+b-a)/c>0)br++;
		if((b+b-c)%a==0&&(b+b-c)/a>0)br++;
		if((a+c)%2==0&&((a+c)/2)%b==0&&((a+c)/2)/b>0)br++;
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}