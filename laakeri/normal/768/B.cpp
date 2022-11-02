#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll sz(ll x){
	if (x==0) return 1;
	if (x==1) return 1;
	return 1+2*sz(x/2);
}

ll get1(ll n, ll r){
	if (n<=0) return 0;
	if (r<=0) return 0;
	ll s=sz(n);
// 	cout<<"qr "<<n<<" "<<r<<" "<<s<<endl;
	if (s<=r){
		return n;
	}
	ll r1=get1(n/2, r);
	if (r>sz(n/2)) r1+=n%2;
	r1+=get1(n/2, r-sz(n/2)-1);
// 	cout<<"r "<<r1<<endl;
	return r1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,l,r;
	cin>>n>>l>>r;
	cout<<get1(n, r)-get1(n, l-1)<<endl;
}