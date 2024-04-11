#include<bits/stdc++.h>
using namespace std;

string a[10] = {"Power","Space","Soul","Mind","Time","Reality"};

map <string, int> f;

int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		if(tmp == "red") f["Reality"] = 1;
		if(tmp == "purple") f["Power"] = 1;
		if(tmp == "green") f["Time"] = 1;
		if(tmp == "blue") f["Space"] = 1;
		if(tmp == "orange") f["Soul"] = 1;
		if(tmp == "yellow") f["Mind"] = 1;
	}
	cout << 6 - n << endl;
	for(int i = 0; i < 6; i++) {
		if(f[a[i]] == 0) {
			cout << a[i] << endl;
		}
	}
	return 0;
}