#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

struct Stud {
	ll i, val, res;
	Stud() {}
};

bool comp1(Stud const &s1, Stud const &s2) {
	return s1.i < s2.i;
}

bool comp2(Stud const &s1, Stud const &s2) {
	return s1.val > s2.val;
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i;
	cin >> n;
	vector<Stud> res(n);
	for (i = 0; i < n; i++) {
		res[i].i = i;
		cin >> res[i].val;
	}
	sort(res.begin(), res.end(), comp2);
	for (i = 0; i < n; i++)
		if (i && (res[i].val == res[i - 1].val))
			res[i].res = res[i - 1].res;
		else
			res[i].res = i;
	sort(res.begin(), res.end(), comp1);
	for (i = 0; i < n; i++)
		cout << res[i].res + 1 << ' ';
	return 0;
}