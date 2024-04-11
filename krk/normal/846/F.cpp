#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1000005;

int n;
vector <int> seq[Maxn];
ld tot;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		seq[a].push_back(i);
	}
	for (int i = 0; i < Maxn; i++) {
		seq[i].push_back(n);
		for (int j = 0; j + 1 < seq[i].size(); j++)
			tot += 2.0l * ld(seq[i][j + 1] - seq[i][j]) * ld(seq[i][j] + 1) - 1ll;
	}
	tot /= ld(n) * ld(n);
	cout << fixed << setprecision(15) << tot << endl;
	return 0;
}