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

ll sum(ll n){
	ll res=0;
	while(n>0){
		if(n&1)res++;
		n/=2;
	}
	return res;
}

int main(){FIN;
	ll n,p; cin>>n>>p;
	fore(i,0,61){
		if(n-i*p>0&&sum(n-i*p)<=i&&n-i*p>=i){
			cout<<i; return 0;
		}
	}	
	cout<<-1;
	return 0;
}