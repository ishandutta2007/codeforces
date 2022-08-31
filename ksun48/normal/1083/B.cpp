#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	LL ns = 0;
	LL ans = 0;
	LL num = 1;
	for(int i = 0; i < n; i++){
		num = (num * 2);
		if(s[i] == 'b') num--;
		if(t[i] == 'a') num--;
		num = min(num, k + 5);
		ans += min(num, k);
	}
	cout << ans << endl;
}