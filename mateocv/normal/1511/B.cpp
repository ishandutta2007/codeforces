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

bool esp(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

ll pot[10],p[10],q[10];

int main(){FIN;
	pot[0]=1;
	fore(i,1,10)pot[i]=10ll*pot[i-1];
	fore(i,0,9){
		fore(j,pot[i],pot[i+1]){
			if(esp(j)){
				if(p[i]==0)p[i]=j;
				else{
					q[i]=j;
					break;
				}
			}
		}
	}
	ll t; cin>>t;
	while(t--){
		ll a,b,c; cin>>a>>b>>c;
		cout<<p[c-1]*p[a-c]<<" "<<p[c-1]*q[b-c]<<"\n";
	}
	
	return 0;
}