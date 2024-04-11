#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll get(ll n, ll k){
	if (n==1) return 1;
	ll mid=(1ll<<(n-1));
	if (k==mid) return n;
	if (k<mid) return get(n-1, k);
	if (k>mid) return get(n-1, k-mid);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	cout<<get(n, k)<<endl;
}