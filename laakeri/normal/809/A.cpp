#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll po[303030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> x(n);
	for (int i=0;i<n;i++) cin>>x[i];
	sort(x.begin(), x.end());
	po[0]=1;
	for (int i=1;i<=n;i++){
		po[i]=po[i-1]*2;
		po[i]%=mod;
	}
	ll v=0;
	for (int i=0;i<n;i++){
		v-=x[i]*po[n-i-1];
		v%=mod;
	}
	sort(x.rbegin(), x.rend());
	for (int i=0;i<n;i++){
		v+=x[i]*po[n-i-1];
		v%=mod;
	}
	v%=mod;
	if (v<0) v+=mod;
	cout<<v<<endl;
}