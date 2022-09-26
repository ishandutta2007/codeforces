#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n,m;
int ans = 0;
int cnt[N];
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= m;++i) {
		int x;	cin >> x;
		++cnt[x];
		bool ok = true;
		for (int j = 1;j <= n;++j) if(cnt[j] == 0) ok = false;
		if(ok) {
			++ans;
			for (int j = 1;j <= n;++j) --cnt[j];
		}
	}
	cout << ans;
}