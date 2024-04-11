#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef complex<int> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<point> v(3);

	for (int i = 0; i < 3; ++i){
		int x, y; cin >> x >> y;
		v[i] = point(x, y);
	}

	vector<point> ans;

	for (int i = 0; i < 3; ++i){
		point a = v[i];

		vector<point> B;

		for (int j = 0; j < 3; ++j)
			if (i != j) B.push_back(v[j]);

		point b = B[0], c = B[1];

		point d = b + c - a;
		bool f = false;
		for (int j = 0; j < (int)ans.size() && !f; ++j)
			if (ans[j] == d) f = true;

		if (!f) ans.push_back(d);
	}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); ++i)
		cout << real(ans[i]) << " " << imag(ans[i]) << endl;

	return 0;
}