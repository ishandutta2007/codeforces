#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	if (n & 1) cout << "black" << endl;
	else{
		cout << "white" << endl;
		cout << 1 << " " << 2 << endl;
	}

	return 0;
}