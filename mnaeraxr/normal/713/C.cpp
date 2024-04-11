#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef complex<int64> rect;

const int64 oo = 0x3f3f3f3f3f3f3f3f;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<rect> rects;
	vector<int64> I;

	I.push_back(-oo);
	rects.push_back(rect(0, 0));


	for (int i = 0; i < n; ++i){
		int64 v; cin >> v;
		v -= i;

		int p = lower_bound(I.begin(), I.end(), v) - I.begin();


		rect cur = rects[p - 1];

		I.insert(I.begin() + p, v);
		rects.insert(rects.begin() + p, cur);

		for (int i = 0; i < (int)I.size(); ++i){
			if (I[i] < v){
				rects[i] += rect(-1, v);
			}
			else{
				rects[i] += rect(1, -v);
			}
		}

		int64 ll = -1;
		int64 vv = -1;

		while (rects.back().real() > 0){
			ll = I.back();
			vv = rects.back().real() * ll + rects.back().imag();

			rects.pop_back();
			I.pop_back();
		}

		I.push_back(ll);
		rects.push_back(rect(0, vv));
	}

	rect last = rects.back();

	int64 answer = last.real() * I.back() + last.imag();

	cout << answer << endl;

	return 0;
}