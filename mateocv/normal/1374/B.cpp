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

ll cant(ll n, ll p){
	ll res=0;
	while(n%p==0)res++,n/=p;
	return res;
}

ll qued(ll n){
	while(n%2==0)n/=2;
	while(n%3==0)n/=3;
	return n==1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll d=cant(n,2),tr=cant(n,3);
		if(qued(n)&&tr>=d){
			cout<<2*tr-d<<"\n";
		}else{
			cout<<-1<<"\n";
		}
	}
	
	return 0;
}