#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll v=n-2;
	for (int i=2;i<=n;i++){
		if (i==2||i==n) v+=(ll)(n-3);
		else v+=(ll)(n-4);
	}
	cout<<v<<endl;
}