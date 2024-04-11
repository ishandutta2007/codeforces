#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 1200;
const int INF = 1e9 + 1000;
int mn[MAXN];
int n;
int a1[MAXN];
int a2[MAXN];

void get(vector<int> vv, int *a) {
	if (vv.empty()) {
		for (int i = 0; i < n; ++i)
			a[i] = INF;
		return;
	}
	cout << vv.size() << "\n";
	for (int i: vv)
		cout << i + 1 << " ";
	cout << "\n";
	cout.flush();
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		mn[i] = INF;
	for (int i = 0; i < 10; ++i) {
		vector<int> vv;
		vector<int> uu;
		for (int j = 0; j < n; ++j) {
			if ((j >> i) & 1)
				vv.push_back(j);
			else
				uu.push_back(j);
		}
		get(vv, a1);
		get(uu, a2);
		for (int j = 0; j < n; ++j) {
			if ((j >> i) & 1)
				mn[j] = min(mn[j], a2[j]);
			else
				mn[j] = min(mn[j], a1[j]);
		}
	}
	cout << -1 << "\n";
	for (int i = 0; i < n; ++i)
		cout << mn[i] << " ";
	cout << "\n";
	cout.flush();
	return 0;
}