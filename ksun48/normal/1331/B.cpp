#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int p = 2; p <= n; p++){
		if(n % p == 0){
			cout << p << n / p << '\n';
			return 0;
		}
	}
}