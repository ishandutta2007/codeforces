#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int n;
int k[N], id[N];
int stk[N], top = 0;

int cmp(int x, int y) { return k[x] < k[y]; }

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> k[i], k[i] = n - 1 - k[i], id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int sum = 0, cnt = 0;
	int ans = -1, A = -1, B = -1;
	for(int i = 1; i <= n; i++) {
		sum += k[id[i]] - cnt;
		stk[++top] = id[i];
		if(sum == top * (top - 1) / 2) {
			cnt += top;
			if(top > 1) {
				if(ans < k[stk[top]] - k[stk[1]]) {
					ans = k[stk[top]] - k[stk[1]];
					A = stk[top], B = stk[1];
				}
			}
			sum = top = 0;
		}
	}
	if(ans == -1) cout << "! " << 0 <<" " << 0 << endl;
	else cout << "! "  << A <<" " << B << endl;
	return 0;
}