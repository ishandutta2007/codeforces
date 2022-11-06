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

vector<ll> a,b;

ll add(ll x, ll y, ll m){
	x+=y;
	if(x>=m)x-=m;
	return x;
}

ll sub(ll x, ll y, ll m){
	x-=y;
	if(x<0)x+=m;
	return x;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll sump=0;
	a.resize(n+1);
	b.resize(n+1);
	a[1]=1;
	sump=1;
	ll va=0;
	fore(i,2,n+1){
		b[i]=add(b[i],1,m);
		if(i+i<=n)b[i+i]=sub(b[i+i],1,m);
	}
	fore(i,2,n+1){
		va=add(va,b[i],m);
		a[i]=add(sump,va,m);
		sump=add(sump,a[i],m);
		for(ll j=i+i;j<=n;j+=i){
			b[j]=add(b[j],a[i],m);
			if(j+j/i<=n)b[j+j/i]=sub(b[j+j/i],a[i],m);
		}
	}
	cout<<a[n]<<"\n";
	
	return 0;
}