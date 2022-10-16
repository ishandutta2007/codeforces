#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool ok = false;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (v == 1) ok = true;
	}
	if (ok) cout << -1 << endl;
	else cout << 1 << endl;
}