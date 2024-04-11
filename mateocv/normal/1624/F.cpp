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

ll n;

ll ulres=-1;

ll ask(ll x){
	if(x==0)return ulres;
	cout<<"+ "<<x<<endl;
	ll resp; cin>>resp;
	ulres=resp;
	return resp;
}

ll solve(ll l, ll r){
	if(l==r)return l;
	ll m=(l+r)/2;
	ll x=((n-m-1)%n+n)%n;
	auto a=ask(x);
	ll res=-1;
	if(a==(m+1+x)/n)res=solve(m+1+x,r+x);
	else res=solve(l+x,m+x);
	return res;
}

int main(){FIN;
	cin>>n;
	auto s=solve(1,n-1);
	cout<<"! "<<s<<endl;
	
	return 0;
}