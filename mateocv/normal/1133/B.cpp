#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll cant[k],lle;
	memset(cant,0,sizeof cant);
	fore(i,0,n){
		cin>>lle;
		cant[lle%k]++;
	}
	ll res=0;
	if(k==1){
		cout<<n-n%2; return 0;
	}
	fore(i,0,k/2){
		res+=min(cant[i],cant[(k-i)%k]);
		if(i==0)res/=2;
	}
	if(k%2==0){
		res+=cant[k/2]/2;
	}else{
		res+=min(cant[k/2],cant[(k-k/2)%k]);
	}
	cout<<2*res;
	
	return 0;
}