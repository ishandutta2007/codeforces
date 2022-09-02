#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i) {
	cout << "? " << i+1 << endl;
	int r;
	cin >> r;
	return r-1;
}
bool dir(int i) {
	int x = ask(i);
	int y = ask(i+1);
	return x < y;
}

void answer(int i) {
	cout << "! " << i+1 << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) answer(0);

	int da = dir(0);
	int db = dir(n-2);
	if (da) answer(0);
	if (! db) answer(n-1);

	int ia = 0, ib = n-1;
	while(ib - ia > 2) {
		int im = (ia + ib) >> 1;
		int dm = dir(im);
		if (dm) ib = im + 1;
		else ia = im;
	}
	answer(ia + 1);
}