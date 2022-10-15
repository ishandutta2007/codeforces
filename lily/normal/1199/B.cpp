#include <bits/stdc++.h>
using namespace std;

#define N 101111

int main() {
	double H, L;
	cin >> H >> L;
	cout << fixed <<  (L * L + H * H) / 2 / H - H << endl;
}