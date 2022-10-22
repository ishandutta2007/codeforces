#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,a,ans[N][N],x,y,x2,y2;
int main() {
	cin >> n;
	x = 1,y = 1;
	x2 = 1,y2 = 2;
	for(int i = 1;i <= n*n;++i) {
		cin >> a;
		if(a != 1 && x <= n) {
			cout << 1 << ' ' << x << ' ' << y << endl;
			y += 2;
			if(y > n) ++x,y = 1 + (x % 2 == 0);
		} else if(a != 2 && x2 <= n) {
			if(a == 1) a = 2;
			cout << 2 << ' ' << x2 << ' ' << y2 << endl;
			y2 += 2;
			if(y2 > n) ++x2,y2 = 1 + (x2 % 2 == 1);
		} else {
			if(x <= n) {
				a = a == 1 ? 3 : 1;
				cout << a << ' ' << x << ' ' << y << endl;
				y += 2;
				if(y > n) ++x,y = 1 + (x % 2 == 0);
			} else {
				a = a == 2 ? 3 : 2;
				cout << a << ' ' << x2 << ' ' << y2 << endl;
				y2 += 2;
				if(y2 > n) ++x2,y2 = 1 + (x2 % 2 == 1);
			}
		}
	}
	return 0;
}