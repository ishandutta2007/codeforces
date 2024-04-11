#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int d;
	cin >> d;
	int r = d;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		r = __gcd(r, a);
	}
	cout << d/r << '\n';
	for(int i = 0; i < d; i += r){
		if(i > 0) cout << ' ';
		cout << i;
	}
	cout << '\n';
}