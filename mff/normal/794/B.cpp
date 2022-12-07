#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double h;
	cin >> n >> h;

	cout.precision(17);

	for (int i = 1; i < n; ++i){
		cout << fixed << h * sqrt(1. * i / n) << endl;
	}

	return 0;
}