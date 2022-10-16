#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int64 calc(int64 a, int64 k){
	return a / k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 k, a, b;
	cin >> k >> a >> b;

	if (a > 0){
		cout << calc(b, k) - calc(a - 1, k) << endl;
	}
	else if (b < 0){
		cout << calc(abs(a), k) - calc(abs(b) - 1, k) << endl;
	}
	else{
		cout << calc(abs(a), k) + calc(abs(b), k) + 1 << endl;
	}

	return 0;
}