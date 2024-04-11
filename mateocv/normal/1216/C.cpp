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

ll x[6],y[6];

ll afuera(ll i, ll j){
	if((x[2]<=i&&i<x[3]&&y[2]<=j&&j<y[3])||(x[4]<=i&&i<x[5]&&y[4]<=j&&j<y[5]))return 0;
	return 1;
}

int main(){FIN;
	fore(i,0,6)cin>>x[i]>>y[i];
	fore(i,x[0],x[1]){
		if(afuera(i,y[0])){
			cout<<"YES"; return 0;
		}
	}
	fore(i,x[0],x[1]){
		if(afuera(i,y[1]-1)){
			cout<<"YES"; return 0;
		}
	}
	fore(i,y[0],y[1]){
		if(afuera(x[0],i)){
			cout<<"YES"; return 0;
		}
	}
	fore(i,y[0],y[1]){
		if(afuera(x[1]-1,i)){
			cout<<"YES"; return 0;
		}
	}
	cout<<"NO";
	
	return 0;
}