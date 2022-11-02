# include <bits/stdc++.h>
using namespace std;

double V, v;
int main() {
	int n, h;
	cin >> n >> h;
	V = 1. * h * h / n;
	for(int i = 0; i < n - 1; ++i) {
		v += V;
		printf("%.10lf ", sqrt(v));
	}
}