#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
 
int main(){FIN;
	ll n,p,d,w; cin>>n>>p>>w>>d;
	ll x=-1,y;
	fore(i,0,d){
		if((i*w)%d==p%d){
			x=i; break;
		}
	}
	if(x==-1){
	    cout<<-1; return 0;
	}
	y=(p-x*w)/d;
	if(y<0||x>n||x+y<0){
		cout<<-1; return 0;
	}
	//cout<<x<<" "<<y<<"\n";
	ll g=__gcd(d,w);
	ll dif=(w-d)/g;
	ll mini=min({(n-x)/(d/g),y/(w/g),(x+y)/dif});
	x+=mini*(d/g);
	y-=mini*(w/g);
	if(x+y>n){
		cout<<-1; return 0;
	}else{
		cout<<x<<" "<<y<<" "<<n-x-y;
	}
	
	return 0;
}