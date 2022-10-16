#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <sstream>
#include <complex>
#include <string>
#include <cstring>

using namespace std;

int main() {
	map<int, int> h_v_r_a;
	int n;
	cin >> n;
	int mx = 0, res = 0;
	for (int i = 0; i < n; i++)
	{
		int id;
		cin >> id;
		h_v_r_a[id]++;
		if (h_v_r_a[id] > mx)
			mx = h_v_r_a[id], res = id;
	}
	cout << res << endl;
}