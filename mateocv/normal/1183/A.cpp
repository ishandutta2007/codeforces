#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll sum(ll x){
	ll res=0;
	while(x>0){
		res+=x%10;
		x/=10;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,n,2000){
		if(sum(i)%4==0){
			cout<<i; return 0;
		}
	}
	
	return 0;
}