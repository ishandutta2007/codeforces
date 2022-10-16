#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double p;

	cin >> n >> p;

	vector<double> A(n), B(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i] >> B[i];

	double lo = 0, hi = 1e18;

	for (int i = 0; i < 100; ++i){
		double t = (lo + hi) / 2;

		double k = 0;

		for (int j = 0; j < n; ++j)
			k += max(A[j] - B[j] / t, 0.);


		if (k <= p)
			lo = t;
		else
			hi = t;
	}

	if (hi > 1e17)
		cout << -1 << endl;
	else{
		cout.precision(10);
		cout << fixed << hi << endl;
	}

	return 0;
}