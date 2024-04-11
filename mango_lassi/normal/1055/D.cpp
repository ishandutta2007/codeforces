#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// TCR
// Computes the Z array in linear time
// z[i] is the length of the longest common prefix of substring
// starting at i and the string
// You can use string s instead of vector<int> s
// z[0]=0 by definition
vector<int> zAlgo(const string& s) {
	int n=s.size();
	vector<int> z(n);
	int l=0;int r=0;
	for (int i=1;i<n;i++) {
		z[i]=max(0, min(z[i-l], r-i));
		while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r) {
			l=i;r=i+z[i];
		}
	}
	return z;
}

const int N = 3000;
const int C = 26;
vector<int> state[N];
string src[N];
string tar[N];
int ia[N];
int ib[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> src[i];
	for (int i = 0; i < n; ++i) cin >> tar[i];
	for (int i = 0; i < n; ++i) {
		state[i].resize(src[i].size());
		for (int j = 0; j < src[i].size(); ++j) {
			state[i][j] = 10000 + (src[i][j] - 'a') + C * (tar[i][j] - 'a');
		}
	}

	// We can find changed part in every string. Changed string must always be equal
	for (int i = 0; i < n; ++i) {
		ia[i] = N;
		ib[i] = -1;
		for (int j = 0; j < src[i].size(); ++j) {
			if (src[i][j] != tar[i][j]) {
				ia[i] = min(ia[i], j);
				ib[i] = max(ib[i], j);
			}
		}
	}

	while(true) {
		bool can = true;
		int tar = -1;
		for (int i = 0; i < n; ++i) {
			if (ia[i] == N) continue;
			if (ia[i] == 0) {
				can = false;
				break;
			}
			if (tar != -1 && state[i][ia[i] - 1] != tar) can = false;
			tar = state[i][ia[i] - 1];
		}
		if (can) {
			for (int i = 0; i < n; ++i) {
				if (ia[i] != N) --ia[i];
			}
		} else {
			break;
		}
	}
	while(true) {
		bool can = true;
		int tar = -1;
		for (int i = 0; i < n; ++i) {
			if (ib[i] == -1) continue;
			if (ib[i]+1 == (int)state[i].size()) {
				can = false;
				break;
			}
			if (tar != -1 && state[i][ib[i] + 1] != tar) can = false;
			tar = state[i][ib[i] + 1];
		}
		if (can) {
			for (int i = 0; i < n; ++i) {
				if (ib[i] != -1) ++ib[i];
			}
		} else {
			break;
		}
	}

	string cha_src = "";
	string cha_tar = "";
	for (int i = 0; i < n; ++i) {
		for (int j = ia[i]; j <= ib[i]; ++j) {
			cha_src.push_back(src[i][j]);
			cha_tar.push_back(tar[i][j]);
		}
		if (! cha_src.empty()) break;
	}
	
	bool fail = false;
	int pl = cha_src.size();
	for (int i = 0; i < n; ++i) {
		string lol = cha_src + "#" + src[i];
		vector<int> z = zAlgo(lol);

		int ind = -1;
		for (int j = 0; j < src[i].size(); ++j) {
			if (z[pl+1+j] == pl) {
				ind = j;
				break;
			}
		}

		if (ind != -1) {
			for (int j = ind; j < ind+pl; ++j) {
				src[i][j] = cha_tar[j-ind];
			}
		}

		fail |= (src[i] != tar[i]);
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << cha_src << '\n';
		cout << cha_tar << '\n';
	}
}