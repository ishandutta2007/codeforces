#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(const vector<int>& qr) {
	cout << "? " << qr.size();
	for (int v : qr) cout << ' ' << v;
	cout << endl;

	string res;
	cin >> res;
	return (res == "YES");
}

void answer(int a, int b) {
	cout << "! " << a << endl;
	string res;
	cin >> res;
	if (res == ":(") {
		cout << "! " << b << endl;
		cin >> res;
		assert(res == ":)");
	}
}

int main() {
	int n;
	cin >> n;
	int m = n;

	// 3 elements:
	//	x y z
	// Ask x twice. Two false -> it isn't x, and x can be eliminated
	// If you get TRUE as an answer, immediately ask y
	//	If you get TRUE as an answer, the answer has to be either x or y, and z can be eliminated
	//	If you get FALSE as an answer, it cannot be y, and y can be eliminated
	// -> Either two questions eliminate x, or three questions eliminate y or z

	vector<int> act(n);
	for (int i = 0; i < n; ++i) act[i] = i + 1;

	while(act.size() > 2) {
		int m = act.size();
		int a = max(1, (2 * m) / 8);
		int b = (m - a) / 2;
		int c = m - a - b;

		vector<int> as, bs, cs;
		for (int i = 0; i < a; ++i) as.push_back(act[i]);
		for (int i = a; i < a + b; ++i) bs.push_back(act[i]);
		for (int i = a + b; i < m; ++i) cs.push_back(act[i]);
		act.clear();

		bool r0 = ask(as);
		if (! r0) r0 = ask(as);

		if (r0) {
			bool r1 = ask(bs);
			if (r1) {
				for (int v : as) act.push_back(v);
				for (int v : bs) act.push_back(v);
			} else {
				for (int v : as) act.push_back(v);
				for (int v : cs) act.push_back(v);
			}
		} else {
			for (int v : bs) act.push_back(v);
			for (int v : cs) act.push_back(v);
		}
	}

	if (act.size() == 1) answer(act[0], act[0]);
	else answer(act[0], act[1]);
}