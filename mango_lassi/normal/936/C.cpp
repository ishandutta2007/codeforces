#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 2000;
int nums[N];
int tmp[N];
int n;

vector<int> res;

void shift(int x) {
	if (x == 0) return;
	res.push_back(x);
	for (int i = 0; i < x; ++i) {
		tmp[i] = nums[n-x+i];
	}
	for (int i = n-x-1; i >= 0; --i) {
		nums[i+x] = nums[i];
	}
	for (int i = 0; i < x; ++i) {
		nums[i] = tmp[x-i-1];
	}
}

int get_ind(int val) {
	for (int i = 0; i < n; ++i) {
		if (nums[i] == val) return i;
	}
	return -1;
}

int main() {
	cin >> n;
	string str, tar;
	cin >> str >> tar;

	for (int i = 0; i < n; ++i) nums[i] = -1;

	bool can = true;
	for (int j = 0; j < n; ++j) {
		can = false;
		for (int i = 0; i < n; ++i) {
			if (str[i] == tar[j] && nums[i] == -1) {
				nums[i] = j;
				can = true;
				break;
			}
		}
		if (!can) break;
	}
	// for (int i = 0; i < n; ++i) cout << nums[i] << ' '; cout << '\n';

	if (can) {
		int high = n >> 1;
		int low = high - 1;
		bool up = true;
		int len = 0;
		while(low >= 0 | high < n) {
			int tar = -1;
			if (up) {
				tar = high;
				++high;
			} else {
				tar = low;
				--low;
			}
			up = !up;
			// cout << "TARGET: " << tar << '\n';

			int ind = get_ind(tar);
			shift(n-ind-1);
			shift(ind-len+1);
			shift(len);
			++len;
		}

		if (up) shift(n);
		cout << res.size() << '\n';
		for (auto it : res) cout << it << ' '; cout << '\n';

		// for (int i = 0; i < n; ++i) cout << nums[i] << ' '; cout << '\n';
	} else {
		cout << "-1\n";
	}
}