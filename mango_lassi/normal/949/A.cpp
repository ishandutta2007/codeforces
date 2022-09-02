#include <iostream>
#include <vector>
using namespace std;

// Possible if every prefix contains more zeroes than ones
// and every suffix contains more zeroes
// always take longest possible sequence greedily?
const int N = 2 * 1e5;
int pre[N];

int main() {
	string str;
	cin >> str;
	int n = str.size();
	vector<int> ones;
	vector<int> zeroes;
	bool can = true;
	for (int i = 0; i < n; ++i) pre[i] = -1;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '0') {
			if (ones.size() > 0) {
				pre[i] = ones.back();
				ones.pop_back();
				zeroes.push_back(i);
			} else {
				zeroes.push_back(i);
			}
		} else {
			if (zeroes.size() > 0) {
				pre[i] = zeroes.back();
				zeroes.pop_back();
				ones.push_back(i);
			} else {
				can = false;
				break;
			}
		}
	}
	if (ones.size() > 0) can = false;
	if (can) {
		cout << zeroes.size() << '\n';
		for (auto it : zeroes) {
			vector<int> seq;
			int cur = it;
			while(cur != -1) {
				seq.push_back(cur+1);
				cur = pre[cur];
			}
			cout << seq.size() << ' ';
			for (int i = seq.size() - 1; i >= 0; --i) cout << seq[i] << ' '; cout << '\n';
		}
	} else {
		cout << "-1\n";
	}
}