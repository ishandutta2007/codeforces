#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans = 11,sz;
string toStr(int n) {
	string ret = "";
	while(n) {
		ret = char((n % 10) + '0') + ret;
		n /= 10;
	} 
	return ret;
}

void calc(int mask,string s) {
	int str = 0;
	int cnt = 0;
	for (int i = 0;i < sz;++i) {
		if (!((mask >> i) & 1)) {
			if(str == 0 && s[i] == '0') return;
			str = 10 * str + s[i] - '0';
		}
		else ++cnt;
	}
	int tmp = floor(sqrt(str));
	if (tmp * tmp == str) 
		ans = min(ans,cnt); 
}
signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
	string tmp = toStr(n);
	sz = tmp.size();
	for (int i = 0;i < (1 << sz) - 1;++i) calc(i,tmp);
	if(ans == 11) {
	//for (int i = 0;i < sz;++i) if(tmp[i] == '0') return cout << sz - 1,0;
		cout << -1;
	}
	else cout << ans;
}