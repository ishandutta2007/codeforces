#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1000005;
int n, a[maxn], maxy, ans;

int main() {
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		a[b]++;
		if (a[b] > maxy) {
			maxy = a[b];
			ans = b;
		}
	}
	cout << ans;
	return 0;
}