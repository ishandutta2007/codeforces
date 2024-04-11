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

#define i64 long long int
int main() {
	i64 A, B;
	cin >> A >> B;
	i64 L1 = 1, R1 = (B - 1) / 2;
	i64 L2 = B - R1, R2 = B - 1;
	if (L2 > A)cout << 0 << endl;else
		if (A >= R2)cout << R2 - L2 + 1 << endl;else
			cout << A - L2 + 1 << endl;
	return 0;
}