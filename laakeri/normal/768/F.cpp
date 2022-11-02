#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	else{
		return (x*pot(x, p-1))%mod;
	}
}

ll inv(ll x){
	return pot(x, mod-2);
}

const int C=500000;
ll ke[C+10];
ll kei[C+10];

ll bin(ll n, ll k){
	if (k<0||k>n) return 0;
	if (n<0) return 0;
	ll r=ke[n];
	r*=kei[k];
	r%=mod;
	r*=kei[n-k];
	r%=mod;
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ke[0]=1;
	kei[0]=1;
	for (ll i=1;i<=C;i++){
		ke[i]=ke[i-1]*i;
		ke[i]%=mod;
		kei[i]=inv(ke[i]);
	}
	int f,w,h;
	cin>>f>>w>>h;
	h++;
	if (w==0){
		cout<<1<<endl;
		return 0;
	}
	if (h>w){
		cout<<0<<endl;
		return 0;
	}
	ll tot=bin(f+w, f);
	ll vv=0;
	for (int i=1;i<=w;i++){
		if (i*h>w) break;
		ll aw=bin(w-i*h+i-1, i-1);
		ll fw=bin(f+i-(i-1), i);
		vv+=aw*fw;
		vv%=mod;
	}
	cout<<(vv*inv(tot))%mod<<endl;
}