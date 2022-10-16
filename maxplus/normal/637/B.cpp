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
	cin.tie(0), ios::sync_with_stdio(0);
	map<string, int> h_v_r_a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string id;
		cin >> id;
		h_v_r_a[id] = i;
	}
	vector<pair<int, string> > cstr;
	for (auto x:h_v_r_a)
	{
		cstr.push_back({ x.second, x.first });
	}
	sort(cstr.rbegin(), cstr.rend());
	for (int i = 0; i < cstr.size(); i++)
	{
		cout << cstr[i].second << endl;
	}
}