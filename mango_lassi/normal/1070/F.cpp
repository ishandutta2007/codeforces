#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> abs;
	vector<int> as;
	vector<int> bs;
	vector<int> zs;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		
		int v;
		cin >> v;
		
		if (str == "00") zs.push_back(v);
		if (str == "10") as.push_back(v);
		if (str == "01") bs.push_back(v);
		if (str == "11") abs.push_back(v);
	}

	sort(abs.begin(), abs.end());
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(zs.begin(), zs.end());
	

	ll res = 0;
	int a_cou = 0;
	int b_cou = 0;
	int cur = 0;
	
	while(true) {
		if (! abs.empty()) {
			res += abs.back();
			++a_cou;
			++b_cou;
			++cur;
			abs.pop_back();
		} else if (as.size() > 0 && bs.size() > 0) {
			res += as.back();
			++a_cou;
			++cur;
			as.pop_back();

			res += bs.back();
			++b_cou;
			++cur;
			bs.pop_back();
		} else {
			int cap = 2 * min(a_cou, b_cou);
			if (as.empty()) {
				swap(as, bs);
				swap(a_cou, b_cou);
			}
			if (zs.empty() || (cap == cur)) {
				if (as.empty()) break;
				if (cap == cur) {
					if (a_cou >= b_cou) break;
				}
				
				res += as.back();
				++a_cou;
				++cur;
				as.pop_back();
			} else {
				if (as.empty() || (as.back() < zs.back())) {
					res += zs.back();
					++cur;
					zs.pop_back();
				} else {
					res += as.back();
					++a_cou;
					++cur;
					as.pop_back();
				}
			}
		}
	}

	cout << res << '\n';
}