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

int main(){FIN;
	ll n,k; cin>>n>>k;
	if(k>=1000){
		cout<<"No"; return 0;
	}
	ll mul[1001];
	mul[0]=1;
	fore(i,1,k+1){
		mul[i]=i*mul[i-1]/__gcd(1ll*i,mul[i-1]);
		if((n+1)%mul[i]!=0){
			cout<<"No"; return 0;
		}
	}
	cout<<"Yes"; return 0;
	return 0;
}