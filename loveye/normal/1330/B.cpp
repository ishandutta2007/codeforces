#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],cnt[N],ncnt[N],res1,res2;
inline void add(int i) {
	++ncnt[a[i]];
	if(ncnt[a[i]] == 1 && a[i] < i) ++res1;
	if(ncnt[i] == 1) ++res1;
}
inline void remove(int i) {
	int l = n-i+1;
	--cnt[a[i]];
	if(cnt[a[i]] == 1 && a[i] <= l) ++res2;
	if(cnt[a[i]] == 0 && a[i] <= l) --res2;
	if(cnt[n-i+1] == 1) --res2;
}
vector<int> ans;
inline void check(int i) {
	if(res1 == i && res2 == n-i) ans.push_back(i);
}
int main() {
	int t;cin >> t;
	while(t--) {
		int ok = 0;
		ans.clear();
		cin >> n;
		res1 = res2 = 0;
		for(int i = 1;i <= n;++i) {
			cin >> a[i];++cnt[a[i]];
			if(cnt[a[i]] > 2)
				ok = 1;
		}
		if(ok == 1) {
			puts("0");
			for(int i = 1;i <= n;++i)
				--cnt[a[i]];
			continue;
		}
		for(int i = 1;i <= n;++i)
			if(cnt[a[i]] == 1) ++res2;
		for(int i = 1;i <= n;++i)
			add(i),remove(i),check(i);
		for(int i = 1;i <= n;++i)
			--ncnt[a[i]];
		cout << ans.size() << endl;
		for(int i = 0;i < ans.size();++i)
			cout << ans[i] << ' ' << n-ans[i] << endl;
	}
	return 0;
}