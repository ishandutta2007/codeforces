#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int N = (1<<8);
const int mask = N-1;
string dp[N][3];
string empt = "";
// if E, second num is 0
// if T, second num is 1
// if F, second num is 2

// true if a is longer or lexicographically more
// false otherwise
bool comp(const string& a, const string& b) {
	if (a == empt) return true;
	if (b == empt) return false;
	if (a.size() < b.size()) return false;
	if (b.size() < a.size()) return true;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] < b[i]) return false;
		if (b[i] < a[i]) return true;
	}
	return true;
}

struct que_el {
	string str;
	int ind;
	int slot;
	
	bool operator<(const que_el& oth) const {
		return comp(str, oth.str);
	}
};
que_el make_que_el(string str, int ind, int slot) {
	que_el tmp;
	tmp.str = str;
	tmp.ind = ind;
	tmp.slot = slot;
	return tmp;
}

string getmin(string a, string b, string c) {
	string res = empt;
	if (comp(res, a)) res = a;
	if (comp(res, b)) res = b;
	if (comp(res, c)) res = c;
	return res;
}

int main() {
	for (int i = 0; i < N; ++i) {
		dp[i][0] = empt;
		dp[i][1] = empt;
		dp[i][2] = empt;
	}
	// preprocess all possible inputs
	int xi = 0 + 0 + 0 + 0 + 16 + 32 + 64 + 128;
	int yi = 0 + 0 + 4 + 8 + 0  + 0  + 64 + 128;
	int zi = 0 + 2 + 0 + 8 + 0  + 32 + 0  + 128;

	priority_queue<que_el> que;

	// tmp.str = "x";
	// tmp.ind = xi;
	// tmp.slot = 2;
	que.push(make_que_el("x", xi, 2));

	// tmp.str = "y";
	// tmp.ind = yi;
	// tmp.slot = 2;
	que.push(make_que_el("y", yi, 2));

	// tmp.str = "z";
	// tmp.ind = zi;
	// tmp.slot = 2;
	que.push(make_que_el("z", zi, 2));

	while(!que.empty()) {
		que_el pr = que.top();
		que.pop();

		string cur = pr.str;
		int ind = pr.ind;
		int typ = pr.slot;

		if (comp(cur, dp[ind][typ])) continue;
		dp[ind][typ] = cur;

		// if the expression P is F, we can make it
		// (F): !P
		// (T): T&P, P
		// (E): 
		if (typ == 2) {
			// (F): !P
			// tmp.str = "!" + cur;
			// tmp.ind = ind ^ mask;
			// tmp.slot = 2;
			que.push(make_que_el("!" + cur, ind ^ mask, 2));
			// (T): T&P
			for (int j = 0; j < N; ++j) {
				if (dp[j][1] != empt) {
					// tmp.str = dp[j][1] + "&" + cur;
					// tmp.ind = ind & j;
					// tmp.slot = 1;
					que.push(make_que_el(dp[j][1] + "&" + cur, ind & j, 1));
					// and other way around
					// tmp.str = cur + "&" + dp[j][1];
					// que.push(tmp);
				}
			}
			// (T): T
			// tmp.str = cur;
			// tmp.ind = ind;
			// tmp.slot = 1;
			que.push(make_que_el(cur, ind, 1));
		}
		// if the expression P is T, we can make it
		// (F): 
		// (T): P&F
		// (E): E|P, P
		if (typ == 1) {
			// (T): P&F
			for (int j = 0; j < N; ++j) {
				if (dp[j][2] != empt) {
					// tmp.str = cur + "&" + dp[j][2];
					// tmp.ind = ind & j;
					// tmp.slot = 1;
					que.push(make_que_el(cur + "&" + dp[j][2], ind & j, 1));
					// and other way around
					// tmp.str = dp[j][2] + "&" + cur;
					// que.push(tmp);
				}
			}
			// (E): E|P
			for (int j = 0; j < N; ++j) {
				if (dp[j][0] != empt) {
					// tmp.str = dp[j][0] + "|" + cur;
					// tmp.ind = ind | j;
					// tmp.slot = 0;
					que.push(make_que_el(dp[j][0] + "|" + cur, ind | j, 0));
					// and other way around
					// tmp.str = cur + "|" + dp[j][0];
					// que.push(tmp);
				}
			}
			// (E): P
			// tmp.str = cur;
			// tmp.ind = ind;
			// tmp.slot = 0;
			que.push(make_que_el(cur, ind, 0));
		}
		// if the expression P is E, we can make it
		// (F): (P)
		// (T): 
		// (E): P|T
		if (typ == 0) {
			// (F): (P)
			// tmp.str = "(" + cur + ")";
			// tmp.ind = ind;
			// tmp.slot = 2;
			que.push(make_que_el("(" + cur + ")", ind, 2));
			// (E): P|T
			for (int j = 0; j < N; ++j) {
				if (dp[j][1] != empt) {
					// tmp.str = cur + "|" + dp[j][1];
					// tmp.ind = ind | j;
					// tmp.slot = 0;
					que.push(make_que_el(cur + "|" + dp[j][1], ind | j, 0));
					// and other way around
					// tmp.str = dp[j][1] + "|" + cur;
					// que.push(tmp);
				}
			}
		}
	}
	
	// ouput
	int am;
	cin >> am;
	for (int i = 0; i < am; ++i) {
		string str;
		cin >> str;
		int val = 0;
		for (int j = 0; j < str.size(); ++j) {
			if (str[j] == '1') val += (1<<j);
		}
		cout << getmin(dp[val][0], dp[val][1], dp[val][2]) << '\n';
	}
}