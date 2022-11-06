#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1003;

int g, d, f, x;
vector<int> br, ob, at, v; 
LL res, t[4];

int whichTeam(int x) {
	if (x > g) {
		if (x > d)
			return 3;
		return 2;
	}
	return 1;
}

int main() {
	cin >> g >> d >> f;

	for (int i = 1; i <= g; ++i) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i <= d; ++i){
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i <= f; ++i){
		cin >> x;
		v.push_back(x);
	}
	d += g;

	// printf("v :: ");
	// for (auto i : v)
	// 	printf("%d ", i);
	// printf("\n");

	for (int i = 0; i < (int)v.size(); ++i) {
		t[1] = t[2] = t[3] = 0;
		// printf("dla :: %d\n", v[i]);
		
		for (int j = 0; j < (int)v.size(); ++j) {
			if (v[j] > v[i] && v[j] <= 2 * v[i]) {
				++t[whichTeam(j + 1)];
				// printf("%d :: %d\n", j + 1, whichTeam(j + 1));
			}
		}
		

		int actTeam = whichTeam(i + 1);
		// printf("aktualny %d :: %d %d %d\n", actTeam, t[1], t[2], t[3]);
		if (actTeam == 1) 
			res += (t[2] * (t[2] - 1LL) / 2LL) * (t[3] * (t[3] - 1LL) * (t[3] - 2LL) / 6LL);
		if (actTeam == 2)
			res += t[1] * t[2] * (t[3] * (t[3] - 1LL) * (t[3] - 2LL) / 6LL);
		if (actTeam == 3) 
			res += t[1] * (t[2] * (t[2] - 1LL) / 2LL) * (t[3] * (t[3] - 1LL) / 2LL);
	}

	cout << res;
}