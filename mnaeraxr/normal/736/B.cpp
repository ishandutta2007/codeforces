#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool isPrime(int n){
	int it = 2;
	while (it * it <= n){
		if (n % it == 0) return false;
		it++;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	if (isPrime(n)){
		cout << 1 << endl;
	}
	else if (isPrime(n - 2)){
		cout << 2 << endl;
	}
	else{
		cout << 2 + (n & 1) << endl;
	}

	return 0;
}