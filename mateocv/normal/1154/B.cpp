#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a=-1,b=-1,c=-1,lle;
	fore(i,0,n){
		cin>>lle;
		if(a==-1||lle==a){
			a=lle;
		}else if(b==-1||lle==b){
			b=lle;
		}else if(c==-1||lle==c){
			c=lle;
		}else {
			cout<<-1; return 0;
		}
	}
	if(b==-1){
		cout<<0; return 0;
	}
	if(c==-1){
		if(abs(a-b)%2==0){
			cout<<abs(a-b)/2; return 0;
		}
		cout<<abs(a-b); return 0;
	}
	ll x=min(a,min(b,c));
	ll z=max(a,max(b,c));
	ll y=a+b+c-x-z;
	if(y-x==z-y){
		cout<<y-x; return 0;
	}else{
		cout<<-1; return 0;
	}
	
	
	return 0;
}