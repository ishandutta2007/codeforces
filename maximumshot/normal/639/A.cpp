#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int maxn = 500000;
int n, k, q, t[maxn];
set < pair <int, int> > s;

int main() {
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == 1) {
			s.insert({ t[r], r});
			if (s.size() > k) {
				s.erase(s.begin());
			}
		}
		else {
			if (s.find({ t[r], r }) == s.end())
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}