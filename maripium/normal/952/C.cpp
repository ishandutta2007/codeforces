#include<bits/stdc++.h>
using namespace std;

int n,a[15];
int main() {
	cin >> n;
	for (int i = 0;i < n;++i) cin >> a[i];
	for (int i = 1;i < n;++i) if(abs(a[i] - a[i - 1]) >= 2) return cout << "NO",0;
	cout << "YES";
	}