#include<bits/stdc++.h>
using namespace std;

int n,x;
int pref[105];
int main() {
	cin >> n;
	int positive = 0;
	int negative = 0;
	for(int i = 1;i <= n;++i) {
		cin >> x;
		if(x < 0) negative += x;
		else positive += x;
	}
	cout << positive - negative << endl;
}