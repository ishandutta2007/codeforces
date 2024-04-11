#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	bool typ;
	string A, B;
	ll res;
	node() { typ = 0; res = 0; }
};

int T;
int n;
map <string, node> M;

int Get(const string &s)
{
	int res = 0;
	for (int i = 0; i + 4 <= s.length(); i++)
		if (s.substr(i, 4) == "haha") res++;
	return res;
}

node Add(node a, node b)
{
	node res;
	if (a.typ == 0 && b.typ == 0) {
		string sum = a.A + b.A;
		res.res = Get(sum);
		if (sum.length() <= 5) { res.typ = 0; res.A = sum; }
		else {
			res.typ = 1;
			res.A = sum.substr(0, 3);
			res.B = sum.substr(int(sum.length()) - 3);
		}
		return res;
	}
	if (a.typ == 0 && b.typ == 1) {
		string sum = a.A + b.A;
		res.res = Get(sum) + b.res;
		res.typ = 1;
		res.A = sum.substr(0, 3);
		res.B = b.B;
		return res;
	}
	if (a.typ == 1 && b.typ == 0) {
		string sum = a.B + b.A;
		res.res = a.res + Get(sum);
		res.typ = 1;
		res.A = a.A;
		res.B = sum.substr(int(sum.length()) - 3);
		return res;
	}
	if (a.typ == 1 && b.typ == 1) {
		string sum = a.B + b.A;
		res.res = Get(sum) + a.res + b.res;
		res.typ = 1;
		res.A = a.A;
		res.B = b.B;
		return res;
	}
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		M.clear();
		node lst;
		while (n--) {
			string nam, op;
			cin >> nam >> op;
			if (op == ":=") {
				string val; cin >> val;
				lst.typ = 0;
				lst.A = val;
				lst.res = Get(val);
			} else {
				string val1, tmp, val2; cin >> val1 >> tmp >> val2;
				lst = Add(M[val1], M[val2]);
			}
			M[nam] = lst;
		}
		cout << lst.res << endl;
	}
    return 0;
}