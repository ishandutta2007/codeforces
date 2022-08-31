#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if((bx-ax) * (cx-ax) < 0 || (by-ay) * (cy-ay) < 0){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}