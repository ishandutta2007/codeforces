#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

void print(int l, int n){
	for (int i = 0; i < n; ++i){
		if (i < l || n - i - 1 < l) cout << "*";
		else cout << "D";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		print(abs(i - n / 2), n);
	}	

	return 0;
}