#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int is(double x){return abs(x-int(x))<1e-9;}

ll get(ll n){
	ll bad=(n+2)/4;
	if(n>=1) bad++;
	if(n>=4) bad++;
	return n-bad;
}

int main(){FIN;
	ll k; cin>>k;
	
	ll l=1,r=1e10;
	while(l<=r){
		ll m=(l+r)/2;
		if(get(m)<k)l=m+1;
		else r=m-1;
	}
	
	cout<<l<<"\n";
}