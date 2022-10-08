#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
long long a[(int) 1e5];

// amb[i][j] is the result for the first i characters of s and the first j characters of "hard"
long long amb[(int) 1e5 + 1][5];
string hard = "hard";

long long ambiguity(int l1, int l2) {
	if(amb[l1][l2] >= 0) {
		//cout << "case 0" << endl;
		return amb[l1][l2];
	}
	//cout << (s[0] == hard[0]) << endl;
	if(l2 == 0) {
		return amb[l1][l2] = -1;
	}else if(l1 == 0) {
		return amb[l1][l2] = 0;
	}else if(s[l1 - 1] == hard[l2 - 1]) {
		long long x = a[l1 - 1] + ambiguity(l1 - 1, l2);
		long long y = ambiguity(l1 - 1, l2 - 1);
		return amb[l1][l2] = (y == -1 ? x : min(x, y));
	}else {
		return amb[l1][l2] = ambiguity(l1 - 1, l2);
	}
}

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 5; j++) {
			amb[i][j] = -1;
		}
	}
	cout << ambiguity(n, 4) << endl;

//	cout << "    _ ";
//	for(int i = 0; i < n; i++) {
//		cout << s[i] << " ";
//	}
//	cout << endl;
//	for(int i = 0; i < 5; i++) {
//		cout << (i > 0 ? hard[i - 1] : '_') << " | ";
//		for(int j = 0; j <= n; j++) {
//			cout << ambiguity(j, i) << " ";
//		}
//		cout << endl;
//	}
}