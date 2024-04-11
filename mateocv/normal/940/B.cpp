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

int main(){FIN;
	ll n,k,a,b; cin>>n>>k>>a>>b;
	ll res=0;
	if(k==1){
		cout<<(n-1)*a; return 0;
	}
	while(n!=1){
		if(n%k!=0){
			res+=a*(n%k-1);
			n-=n%k-1;
			if(n==1)break;
			else{
				n--; res+=a;
			}
		}else{
			res+=min(b,a*(n-n/k));
			n/=k;
		}
	}
	cout<<res;
	
	return 0;
}