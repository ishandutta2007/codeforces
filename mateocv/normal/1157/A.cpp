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

ll f(ll n){
	n++;
	while(n%10==0){
		n/=10;
	}
	return n;
}

int main(){FIN;
	ll n; cin>>n;
	set<ll> s;
	s.insert(n);
	while(1){
		n=f(n);
		if(s.count(n)){
			break;
		}else{
			s.insert(n);
		}
	}
	cout<<SZ(s);
	return 0;
}