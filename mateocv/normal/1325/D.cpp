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
	ll x,s; cin>>x>>s;
	if(x==s){
		if(x==0){
			cout<<0; return 0;
		}else{
			cout<<"1\n"<<x; return 0;
		}
	}
	if(x>s){
		cout<<-1; return 0;
	}
	if((s-x)%2){
		cout<<-1; return 0;
	}
	fore(j,0,61){
		if(((1ll<<j)&((s-x)/2))&&((1ll<<j)&x)){
			cout<<"3\n"<<x<<" "<<(s-x)/2<<" "<<(s-x)/2; return 0;
		}
	}
	cout<<2<<"\n"<<x+(s-x)/2<<" "<<(s-x)/2;
	return 0;
}