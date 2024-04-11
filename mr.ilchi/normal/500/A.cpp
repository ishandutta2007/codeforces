#include <bits/stdc++.h>
using namespace std;

int n,t;
int a[1<<20];

int main(){	
	cin >> n >> t;
	for (int i=1; i<n; i++)
		cin >> a[i];
	int cur = 1;
	while (cur < t)
		cur = cur + a[cur];
	cout << (cur == t ? "YES" : "NO") << endl;
	return 0;
}