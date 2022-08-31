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
int n, m;
int arr[1000][1000];


int main() {
	cin >> n >> m;
	int now = 1;
	for (int i = 0; i < n; ++i) {
		if (now <= m)
			arr[i][0] = now++;
		if (now <= m)
			arr[i][3] = now++;
	}
	for (int i = 0; i < n; ++i) {
		if (now <= m)
			arr[i][1] = now++;
		if (now <= m)
			arr[i][2] = now++;
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i][1])
			cout << arr[i][1] << " ";
		if (arr[i][0])
			cout << arr[i][0] << " ";
		if (arr[i][2])
			cout << arr[i][2] << " ";
		if (arr[i][3])
			cout << arr[i][3] << " ";
	}
	cout << "\n";
	return 0;
}