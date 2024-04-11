#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
int T;
string a;
int main() {
	cin >> T;
	for(; T--; ) {
		cin >> a;
		int n = a.size();
		int cnt = 0;
		for(int i = 1; i < n; i++) {
			if(a[i] != a[i - 1]) {
				cnt++;
			}
		}
		cnt += 1;
		if(cnt & 1) {
			if(a[0] == '0') cnt++;
			else cnt--;
		}
		cnt /= 2;
		if(cnt == 0) cout << 0 << endl;
		else if(cnt == 1) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}