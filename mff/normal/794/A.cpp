#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int f = 0, n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (b < v && v < c)
			f++;
	}

	cout << f << endl;

	return 0;
}