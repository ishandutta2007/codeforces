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

	int zeroes = 0;
	vector<int> lefts;
	vector<int> rights;

	for (int i = 0; i < n; ++i) {
		string seq;
		cin >> seq;

		int pl = 0;
		int sl = 0;

		int cou = 0;
		for (int j = 0; j < seq.size(); ++j) {
			if (seq[j] == ')') ++cou;
			else --cou;
			pl = max(pl, cou);
		}
		bool left_works = (bool)(pl == cou);

		cou = 0;
		for (int j = (int)seq.size()-1; j >= 0; --j) {
			if (seq[j] == '(') ++cou;
			else --cou;
			sl = max(sl, cou);
		}
		bool right_works = (bool)(sl == cou);

		if (left_works && right_works) {
			++zeroes;
		} else if (left_works) {
			lefts.push_back(pl);
		} else if (right_works) {
			rights.push_back(sl);
		}
	}

	sort(lefts.begin(), lefts.end());
	sort(rights.begin(), rights.end());

	int res = zeroes / 2;
	int j = 0;
	for (int i = 0; i < lefts.size(); ++i) {
		while((j < rights.size()) && (rights[j] < lefts[i])) ++j;
		if ((j < rights.size()) && (rights[j] == lefts[i])) {
			++res;
			++j;
		}
	}
	cout << res << '\n';
}