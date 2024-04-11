#include <bits/stdc++.h>

using namespace std;

#define NEXT(i) (i == n - 1 ? 0 : i + 1)

typedef complex<double> point;

double dot(point a, point b){
	return real( conj(a) * b );
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	double answer = 1e18;

	vector<point> P(n);

	for (int i = 0; i < n; ++i){
		double x, y;
		cin >> x >> y;
		P[i] = point(x, y);
	}

	for (int i = 0; i < n; ++i){
		answer = min( answer, abs(P[i] - P[NEXT(i)]) );

		point a = P[i], b = P[ NEXT(i) ], c = P[ NEXT(NEXT(i)) ];
		a -= c; b -= c;
		a *= point(0, 1);
		a /= abs(a);

		answer = min(answer, abs( dot(a, b) ) / 2 );
	}

	cout.precision(10);
	cout << fixed << answer << endl;

	return 0;
}