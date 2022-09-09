#include<bits/stdc++.h>
using namespace std;

int x, y;

int main() {
	cin >> x >> y;
	if(x == y) {
		cout << "=";
		return 0;
	}
	if(x <= 10 && y <= 10) {
		int ans1 = 1, ans2 = 1;
		for(int i = 1; i <= x; i++) ans2 *= y;
		for(int i = 1; i <= y; i++) ans1 *= x;
		if(ans1 == ans2) cout << "=";
		if(ans1 > ans2) cout << ">";
		if(ans1 < ans2) cout << "<";
		return 0;
	}
	if(x == 1) {
		cout << "<";
		return 0;
	}
	if(y == 1) {
		cout << ">";
		return 0;
	}
	if(x < y) cout << ">";
	if(x > y) cout << "<";
	return 0;
}