#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int64 oo = 0x3f3f3f33f3f3f3f;
const int MAXN = (int)1e5 + 10;

bool dbg;

int64 solve(vector<pair<int64,bool>> v, int64 b, int64 c, int k){
	int64 ans = oo;

	multiset<int64> s;

	int64 sum = 0, cur, tmp;

	for (auto val : v){
		if (val.second){
			tmp = 5 - val.first % 5;
			if (tmp == 5) tmp = 0;
			cur = (val.first + 4) / 5 * b - c * tmp;
			sum += cur;
			s.insert(cur);
			if ((int)s.size() > k){
				auto it = s.begin();
				sum -= *it;
				s.erase(it);
			}
		}

//		if (dbg) cout << val.first << " " << val.second << " " << cur << " " << sum << " " << ans << endl;

		if (val.first % 5 == 0 && (int)s.size() == k){
			ans = min(ans, b * (val.first / 5) * k - sum);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int64 b, c;
	cin >> b >> c;
	b = min(b, 5 * c);

	vector<pair<int64,bool>> v;
	int64 mn = oo;

	for (int i = 0; i < n; ++i){
		int64 vv; cin >> vv;
		for (int j = 0; j < 5; ++j)
			v.push_back({vv + j, j == 0});
		mn = min(mn, vv);
	}

	for (auto &vv : v){
		vv.first -= mn;
//		if (vv.second) cout << vv.first << endl;
	}

	sort(v.begin(), v.end());

	int64 ans = oo;

	for (int i = 0; i < 5; ++i){
//		dbg = i == 0;
		int64 cc = solve(v, b, c, k);
		ans = min(ans, cc);
		for (auto &val : v)
			++val.first;
	}

	cout << ans << endl;

	return 0;
}