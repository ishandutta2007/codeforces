#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n,k,cnt[30];
char s[N];
int gcd(int x,int y) {
	return !y ? x :gcd(y,x % y);
}
inline int check(int len) {
	int g = gcd(len,k % len),res = len / g,cc = 0;
	for(int i = 0;i < 26;++i)
		cc += cnt[i] / res;
	return cc >= g;
}
int main() {
	ios::sync_with_stdio();
	int t;cin >> t;
	while(t--) {
		memset(cnt,0,sizeof cnt);
		cin >> n >> k >> s+1;
		for(int i = 1;i <= n;++i)
			++cnt[s[i]-'a'];
		for(int i = n;i >= 1;--i)
			if(check(i)) {
				cout << i << endl;
				break;
			}
	}
	return 0;
}