#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int q;
	for(cin >> q; q--; ) {
		i64 a, b, m;
		cin >> a >> b >> m;
		if(a == b) {
			cout << "1 " << a <<"\n";
			continue;
		}
		i64 s = a;
		a++;
		int len = 1;
		while((a << 1) <= b) len++, a <<= 1;
		b -= a;
		vector<i64> ans(len), res(len + 1);
		for(int i = len - 1; i >= 1; i--) {
			i64 t = min(m - 1, (b >> (i - 1)));
			b -= t << (i - 1);
			ans[i] = t + 1;
		}
		i64 t = min(m - 1, b);
		b -= t, ans[0] = t + 1;
		if(b > 0) {
			cout << "-1\n";
			continue;
		}
		res[0] = s;
		for(int i = 1; i <= len; i++) {
			res[i] = s + ans[len - i];
			s += res[i];
		}
		cout << len + 1 <<" ";
		for(int i = 0; i <= len; i++) cout << res[i] <<" \n"[i == len];
	}
	return 0;
}