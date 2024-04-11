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
	ll n; cin>>n;
	ll l[n],r[n],k;
	fore(i,0,n){
		cin>>l[i]>>r[i];
	}
	cin>>k; k--;
	ll res=0;
	fore(i,0,n){
		if(k>=r[i]){
			res++;
		}else{
			break;
		}
	}
	cout<<n-res;
	
	
	return 0;
}