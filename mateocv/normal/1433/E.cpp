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

ll fact(ll n){
	ll res=1;
	fore(i,1,n+1){
		res*=i;
	}
	return res;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact(n)/(fact(k)*fact(n-k));
}

int main(){FIN;
	ll n; cin>>n;
	ll res=comb(n-1,n/2)*fact(n/2-1)*fact(n/2-1);
	cout<<res<<"\n";	
	return 0;
}