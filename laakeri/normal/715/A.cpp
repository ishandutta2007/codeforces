#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nn;
	cin>>nn;
	ll m=2;
	for (ll k=1;k<=nn;k++){
		//cout<<"m "<<m<<endl;
		ll n=m/k;
		ll x=k*(k+1)*(k+1)-n;
		cout<<x<<'\n';
		m=(k*(k+1));
	}
}