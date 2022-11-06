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
		ll x; cin>>x;
		ll res=0;
		if(x>=1900)res=1;
		else if(1600<=x&&x<=1899)res=2;
		else if(1400<=x&&x<=1599)res=3;
		else if(x<=1399)res=4;
		cout<<"Division "<<res<<"\n";
	}
	
	return 0;
}