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

int arr[11] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int check(int x) {
	cout << x << "\n";
	cout.flush();
	string s;
	cin >> s;
	if (s == "yes")
		return 1;
	else
		return 0;

}
int main() {
	int c2 = check(2);
	int c3 = check(3);
	int c5 = check(5);
	int c7 = check(7);
	if (c2 + c3 + c5 + c7 == 0) {
		cout << "prime" << endl;
		return 0;
	}
	if (c2 + c3 + c5 + c7 >= 2) {
		cout << "composite" << endl;
		return 0;
	}
	if (check(4) || check(25) || check(9) || check(49)) {
		cout << "composite" << endl;
		return 0;
	}
	for (int i = 0; i < 11; ++i) {
		if (check(arr[i])) {
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
	return 0;
}