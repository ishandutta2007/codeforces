#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int c, d;
		cin >> c >> d;
		if((c + d) & 1) cout << -1 << endl;
		else {
			if(c == 0 && d == 0) cout << 0 << endl;
			else {
				if(c == d) cout << 1 << endl;
				else cout << 2 << endl;
			}
		}
	}
	return 0; 
}