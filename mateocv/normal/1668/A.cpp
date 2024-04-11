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
		ll n,m; cin>>n>>m;
		if(n>m)swap(n,m);
		ll res=-1;
		if(n==1){
			if(m==1)res=0;
			if(m==2)res=1;
		}else{
			res=2ll*(n-2);
			m-=n-2;
			res+=2ll*m-2;
			res-=(m&1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}