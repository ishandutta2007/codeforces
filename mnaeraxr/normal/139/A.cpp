#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v(7);
	int s = 0;
	for (int i = 0; i < 7; ++i){
		cin >> v[i];
		s += v[i];
	}
	n %= s;
	if (n == 0){
		for (int i = 6; i >= 0; --i){
			if (v[i]){
				cout << i + 1 << endl;
				exit(0);
			}
		}
	}
	else{
		for (int i = 0; i < 7; ++i){
			n -= v[i];
			if (n <= 0){
				cout << i + 1 << endl;
				exit(0);
			}
		}
	}

	cout << "THIS IS BAD" << endl;

	return 0;
}