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
	ll n,m; cin>>n>>m;
	if(n>m)swap(n,m);
	if(n==1){
		cout<<m-(m%6)+2*max(0ll,(m%6)-3); return 0;
	}
	if(n==2){
		if(m==7){
			cout<<12; return 0;
		}
		if(m>=4){
			cout<<n*m; return 0;
		}
		if(m==3){
			cout<<4; return 0;
		}
		if(m==2){
			cout<<0; return 0;
		}
	}
	cout<<n*m-((n*m)%2);
	return 0;
}