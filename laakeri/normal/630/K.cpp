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
	ll n;
	cin>>n;
	ll v=0;
	for (ll i=0;i<(1<<9);i++){
		ll lcm=1;
		for (ll j=0;j<9;j++){
			if (i&(1<<j)){
				if (lcm==1) lcm=j+2;
				else lcm=((j+2)/__gcd(j+2, lcm))*lcm;
			}
		}
		if (__builtin_popcount(i)%2==0) v+=n/lcm;
		else v-=n/lcm;
	}
	cout<<v<<endl;
}