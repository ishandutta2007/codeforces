#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define long double double;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

double solveQuadratic(double A, double B, double C){
	double D = B * B - 4 * A * C;
//	cout << "Discriminant: " << D << endl;
	assert(D >= -1e-7);
	D = max(D, 0.0);
	double d = sqrt(D);
	double x1 = (-B + d) / 2 / A;
	double x2 = (-B - d) / 2 / A;
	if (-eps <= x1 && x1 <= 1 + eps) return x1;
	return x2;
}

double solve(double sigmaA, double sigmaB, double k1, double k2){
	double A = 0, B = 0, C = 0;
	C = k1 * (1 - sigmaB) - k2 * sigmaB;
	B = -sigmaA * (1 - sigmaB) + (1 - sigmaA) * sigmaB - k2 - k1;
	A = 1;
//	cout << A << " " << B << " " << C << endl;
	double x = solveQuadratic(A, B, C);
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<double> p1(n), p2(n);
	vector<double> a1(n), a2(n);

	double sigmaA = 0, sigmaB = 0;

	for (int i = 0; i < n; ++i) cin >> p1[i];
	for (int i = 0; i < n; ++i) cin >> p2[i];

	for (int i = 0; i < n; ++i){
		a2[i] = solve(sigmaA, sigmaB, p1[i], p2[i]);
		a1[i] = sigmaB + a2[i] < eps ? 0 : (p1[i] - a2[i] * sigmaA) / (sigmaB + a2[i]);

//		cout << "partial solution" << endl;
//		cout << a1[i] << "  " << a2[i] << endl;

		sigmaA += a1[i];
		sigmaB += a2[i];
	}

	cout.precision(20); // Change into 10
	for (int i = 0; i < n; ++i) cout << fixed << a1[i] << " ";
	cout << endl;
	for (int i = 0; i < n; ++i) cout << fixed << a2[i] << " ";
	cout << endl;

	return 0;
}