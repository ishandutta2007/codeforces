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
	ll p=0;
	ll i=1;
	while (p+i<n){
		p+=i;
		i++;
	}
	cout<<n-p<<endl;
}