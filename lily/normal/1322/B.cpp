#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int L = 25;
const int N = 400444;

int n, a[N];

int yes(vector <int> &b, int offset, int lim) {
	//cerr << "yes" << lim << " " << b.size() << endl;
	int m = (int)b.size();
	if (m == 0) return 0;
	int i = 0, j = 0;
/*	for (int i = 0; i < m; i++) {
		cerr << (b[i] & offset) << endl;
	}*/
	while (j < m && (b[m - 1 - i] & offset) + (b[m - 1 - j] & offset) >= lim) j++; 
	//cerr << i << " " << j << endl;
	int cnt = 0;
	for ( ; i < m; i++) {
		while (j > 0 && (b[m - 1 - i] & offset) + (b[m - 1 - (j - 1)] & offset) < lim) j--;
		cnt ^= min(j, i);
	}
	//cerr << cnt << endl;
	return cnt;
}

vector <int> v[2];

int no(int offset, int lim) {
	//cerr << "no" << endl;
	int m = (int)v[0].size(), k = (int)v[1].size();
	int i = 0, j = 0;
	while (j < k && (v[0][i] & offset) + (v[1][j] & offset) < lim) j++; 
	int cnt = 0;
	for ( ; i < m; i++) {
		while (j > 0 && (v[0][i] & offset) + (v[1][j - 1] & offset) >= lim) j--;
		cnt ^= j;
	}
	return cnt;
}

vector <int> t[2];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		v[a[i] & 1].push_back(a[i]);
	}
/*
	int aa = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			aa ^= a[i] + a[j];
		}
	cout << aa << endl;
*/

	int ans = v[0].size() & v[1].size() & 1;
	for (int i = 1; i < L; i++) {
		t[0].clear(); t[1].clear();
		for (auto &j : v[0]) {
			t[(j >> i) & 1].push_back(j);
		}
		for (auto &j : v[1]) {
			t[(j >> i) & 1].push_back(j);
		}
		swap(v[0], t[0]);
		swap(v[1], t[1]);
		int cnt = 0;
		cnt ^= yes(v[0], (1 << i) - 1, 1 << i);
		cnt ^= yes(v[1], (1 << i) - 1, 1 << i);
		cnt ^= no((1 << i) - 1, 1 << i);
		ans ^= (cnt & 1) << i;
	}
	//for (auto i : v[0]) cerr << i << " " ;
	//cerr << endl;
	cout << ans << endl;
}