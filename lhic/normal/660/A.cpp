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

int n;
vector<int> vv;

int main() {
	scanf("%d", &n);
	int lst;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (i == 0)
			vv.push_back(a);
		else {
			if (__gcd(lst, a) == 1) {
				vv.push_back(a);
			}
			else {
				vv.push_back(1);
				vv.push_back(a);
			}
		}
		lst = a;
	}
	cout << vv.size() - n << "\n";
	for (int i: vv)
		cout << i << " ";
	cout << "\n";
	return 0;
}