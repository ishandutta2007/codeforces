#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e5 + 10;
int n, p[N];
int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		reverse(p + 1, p + n + 1);
		int now = 0, pre = n + 1;
		for(int i = n; i >= 1; i--) {
			if(p[i] > now) {
				now = p[i];
				reverse(p + i + 1, p + pre + 1);
				pre = i;
			}
		}
		reverse(p + 1, p + pre + 1);
		for(int i = 1; i <= n; i++) cout << p[i] <<' ';
		cout << endl;
	}
    return 0;
}