#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int isp(ll n){
	for (ll d=2;d*d<=n;d++){
		if (n%d==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	if (isp(n)){
		cout<<1<<endl;
		return 0;
	}
	if (n%2==0){
		cout<<2<<endl;
		return 0;
	}
	if (isp(n-2)){
		cout<<2<<endl;
		return 0;
	}
	cout<<3<<endl;
}