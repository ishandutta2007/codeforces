#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define vi vector<int>
using namespace std;
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	int t = (n - k) / 2 + 1;
	for(int i = 1; i <= n; i++) {
		if((n - i) % t == t - 1) {
			cout << 0;
		} else {
			cout << 1;
		}
	} 
	cout << endl;
	return 0;
}