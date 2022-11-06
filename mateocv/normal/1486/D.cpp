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

const int MAXN=200005;

ll n,k;

ll a[MAXN],b[MAXN],mini[MAXN];

bool can(ll m){
	b[0]=0;
	fore(i,0,n){
		b[i+1]=b[i]+(a[i]>=m?1:-1);
	}
	mini[0]=b[0];
	fore(i,0,n){
		mini[i+1]=min(mini[i],b[i+1]);
	}
	fore(i,0,n+1){
		if(i>=k){
			if(b[i]>mini[i-k])return 1;
		}
	}
	return 0;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=n+1;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	
	return 0;
}