#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, chk[100100];
vector<int> v;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for(int i=2;i<=n;i++) if(!chk[i]){
		for(int j=i+i;j<=n;j+=i) chk[j] = i;
	}
	
	if(n == 2){
		cout << "1\n1";
		return 0;
	}

	if(!chk[n]){
		cout << n-2 << "\n";
		for(int i=1;i<=n-2;i++) cout << i << " ";
		return 0;
	}

	ll g = 1;
	for(int i=1;i<n-1;i++) if(__gcd(i, n) == 1) v.push_back(i), g = g * i % n;
	if((g * (n-1)) % n == 1) v.push_back(n-1);

	cout << v.size() << "\n";
	for(auto x : v) cout << x << " ";
}