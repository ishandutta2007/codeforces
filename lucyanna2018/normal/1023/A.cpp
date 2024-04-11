#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

string A, B;
int main() {
	int LA, LB;
	cin >> LA >> LB;
	cin >> A >> B;
	int id = -1;
	for (int i = 0; i < LA; i++)if (A[i] == '*') {
		id = i;
		break;
	}
	if (id == -1) {
		cout << (A == B ? "YES" : "NO") << endl;
		return 0;
	}
	int sufflen = LA - id - 1;
	cout << (LA - 1 <= LB && B.substr(0, id) == A.substr(0, id) && B.substr(LB - sufflen, sufflen) == A.substr(LA - sufflen, sufflen) ? "YES" : "NO") << endl;
	return 0;
}