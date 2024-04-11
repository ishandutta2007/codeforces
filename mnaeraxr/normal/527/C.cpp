#include <bits/stdc++.h>

using namespace std;

#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

multiset<int> V, H, pV, pH;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v, h, n;
	cin >> v >> h >> n;

	V.insert(v);
	pV.insert(0); pV.insert(v);
	H.insert(h);
	pH.insert(0); pH.insert(h);

	while (n--)
	{
		char c;
		int p;
		cin >> c >> p;
		if (c == 'V'){
			auto cur = pV.lower_bound(p);
			auto ccur = cur;
			ccur--;
			int sz = *cur - *ccur;
			auto f = V.lower_bound(sz);
			V.erase(f);
			pV.insert(p);
			V.insert(p - *ccur);
			V.insert(*cur - p);
		}
		else{
			auto cur = pH.lower_bound(p);
			auto ccur = cur;
			ccur--;
			int sz = *cur - *ccur;
			auto f = H.lower_bound(sz);
			H.erase(f);
			pH.insert(p);
			H.insert(p - *ccur);
			H.insert(*cur - p);
		}

		auto rh = H.end(), rv = V.end();
		rh--; rv--;
		cout << 1LL * (*rh) * (*rv) << endl;
	}

	return 0;
}