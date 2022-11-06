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
		ll a,b,c,d; cin>>a>>b>>c>>d;
		ll x,y,xi,yi,xf,yf; cin>>x>>y>>xi>>yi>>xf>>yf;
		if(xi<=x+b-a&&x+b-a<=xf&&yi<=y+d-c&&y+d-c<=yf){
			ll cumx=0,cumy=0;
			if(a==0||b==0){
				cumx=1;
			}else if(a!=0&&b!=0&&xi!=xf){
				cumx=1;
			}
			if(c==0||d==0){
				cumy=1;
			}else if(c!=0&&c!=0&&yi!=yf){
				cumy=1;
			}
			if(cumx&&cumy){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}