#include <bits/stdc++.h>
#define x first
#define y second
#define vi vector<int> 
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e5 + 10;
int t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	for(; t--; ) {
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		int even = (a + b) / 2, odd = (a + b) % 2 + 1;
		cout << (a + 1) * odd << endl;
		for(int i = even - a; i <= even + a; i += 2) {
			cout << i <<" ";
			if(odd - 1) cout << i + 1 <<" ";
		}
		cout << endl;
	}
	return 0;
}