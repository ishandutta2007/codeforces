#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int y, b, r;
	cin >> y >> b >> r;
	int x = y;
	x = min(x, b-1);
	x = min(x, r-2);
	cout << 3*x + 3 << endl;
}