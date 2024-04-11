#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 5;
 
int n,res[N],a[N];
int child[N << 4][2];
int have[N << 4][2];
int now = 0;
void add(int x) {
	int pre = 0;
	for(int i = 29;i >= 0;--i) {
		int y = (x >> i) & 1;
		if(have[pre][y] == 0) child[pre][y] = ++now;
		++have[pre][y];
		pre = child[pre][y];
	}
}
 
void del(int x) {
	int pre = 0;
	for(int i = 29;i >= 0;--i) {
		int y = (x >> i) & 1;
		--have[pre][y];
		pre = child[pre][y];
	}
}
 
int query(int x) {
	int pre = 0;
	int ans = 0;
	for(int i = 29;i >= 0;--i) {
		int y = (x >> i) & 1;
		if(y == 1) {
			if(have[pre][1] == 0) pre = child[pre][0];
			else {
				ans |= (1 << i);
				pre = child[pre][1];
			}
		}
		else {
			if(have[pre][0] == 0) {
			ans |= (1 << i);
			pre = child[pre][1];
		}
			else pre = child[pre][0];
		}
	}
	del(ans);
	return ans ^ x;
}
 
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= n;++i) {
		int x;	cin >> x;
		add(x);
	}
	for(int i = 1;i <= n;++i) res[i] = query(a[i]);
	for(int i = 1;i <= n;++i) cout << res[i] << ' '; 
}