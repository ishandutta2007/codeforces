#include "bits/stdc++.h"
using namespace std;

const int N = 2e3 + 5;

int n;
char s[N],t[N],_s[N];
vector<int> ans;

void calc(int x) {
	ans.push_back(x);
	for (int i = n - 1; i >= n - x; --i) _s[n - 1 - i] = s[i];
	for (int i = 0; i < n - x; ++i) _s[x + i] = s[i];
	for (int i = 0; i < n; ++i) s[i] = _s[i];
} 

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) cin >> s[i];
	for(int i = 0;i < n;++i) cin >> t[i];
	/*cout << endl;
	cout << endl;*/
 	for(int i = 0;i < n;++i) {
		int x = -1;
		for(int j = i;j < n;++j) {
			if(s[j] == t[n - 1 - i]) {
				x = j;
				break;
			}
		}
		if(x == -1) return cout << -1 << endl,0;
		calc(n);
		calc(x);
		calc(1);
		/*for(int i = 0;i < n;++i) cout << s[i];
		cout << endl;*/
	}
	//cout << endl;
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();++i) cout << ans[i] << ' ';
}