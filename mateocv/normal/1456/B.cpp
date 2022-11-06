#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll maxp(ll n){
	return 31-__builtin_clz(n);
}

const int MAXN=100005;

ll a[MAXN],b[MAXN],xp[MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)b[i]=maxp(a[i]);
	fore(i,0,n-2){
		if(b[i]==b[i+2]){
			cout<<1<<"\n";
			return 0;
		}
	}
	assert(n<=100);
	fore(i,0,n)xp[i+1]=xp[i]^a[i];
	ll res=2*n;
	fore(i,0,n){
		fore(j,i+1,n){
			fore(k,j+1,n+1){
				if((xp[j]^xp[i])>(xp[k]^xp[j])){
					//cout<<i<<" "<<j<<" "<<k<<" "<<xp[j]-xp[i]<<" "<<xp[k]-xp[j]<<"\n";
					res=min(res,j-i-1+k-j-1);
				}
			}
		}
	}
	if(res==2*n)cout<<"-1\n";
	else cout<<res<<"\n";
	
	return 0;
}