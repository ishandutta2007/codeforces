#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t,n,k;
string s;
inline int calc(int x) {
	if(x <= 0) return 0;
	return 1 + (x-1) / (k+1);
}
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		int cnt = 0,ans = 0,is1 = 0;
		cin >> n >> k >> s;
		for(int i = 0;i < s.length();++i)
			if(s[i] == '0') ++cnt;
			else ans += calc(cnt - k - (is1 ? k : 0)),cnt = 0,is1 = 1;
		ans += calc(!is1 ? cnt : cnt-k);
		cout << ans << endl;
	}
	return 0;
}