#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll mod=1000000;

ll p10[10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	p10[0]=1;
	for (ll i=1;i<10;i++){
		p10[i]=p10[i-1]*10ll;
	}
	ll x=n;
	ll r=0;
	for (int j=0;j<5;j++){
		if (j==0) r+=p10[2]*(x%10);
		if (j==1) r+=p10[1]*(x%10);
		if (j==2) r+=p10[3]*(x%10);
		if (j==3) r+=p10[0]*(x%10);
		if (j==4) r+=p10[4]*(x%10);
		x/=10;
	}
	ll rr=1;
	for (int j=0;j<5;j++){
		rr*=r;
		rr%=mod;
	}
	string v;
	ll xx=rr;
	for (int j=0;j<5;j++){
		v+=(char)('0'+xx%10);
		xx/=10;
	}
	reverse(v.begin(), v.end());
	cout<<v<<endl;
}