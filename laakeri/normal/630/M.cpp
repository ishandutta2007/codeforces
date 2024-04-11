#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll get(ll x, ll r){
	x-=90ll*r;
	x=((x%360)+360)%360;
	return min(x, 360-x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x;
	cin>>x;
	ll mi=get(x, 0);
	mi=min(mi, get(x, 1));
	mi=min(mi, get(x, 2));
	mi=min(mi, get(x, 3));
	for (int i=0;i<4;i++){
		if (get(x, i)==mi){
			cout<<i<<endl;
			return 0;
		}
	}
}