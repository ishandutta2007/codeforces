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


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 300000;

int n;

int a[MAXN];
int ans[MAXN];

int gol[MAXN];
int gor[MAXN];

vector<int> st;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	st.clear();
	for (int i = 0; i < n; ++i)
		gol[i] = -1, gor[i] = n;
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && a[st.back()] > a[i])
			gor[st.back()] = i, st.pop_back();
		st.push_back(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && a[st.back()] > a[i])
			gol[st.back()] = i, st.pop_back();
		st.push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		ans[gor[i] - gol[i] - 1] = max(ans[gor[i] - gol[i] - 1], a[i]);
	}
	for (int i = n - 1; i >= 1; --i)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}