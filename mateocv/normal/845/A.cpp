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
	ll n; cin>>n;
	ll a[2*n];
	fore(i,0,2*n){
		cin>>a[i];
	}
	sort(a,a+2*n);
	if(a[n]>a[n-1]){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}