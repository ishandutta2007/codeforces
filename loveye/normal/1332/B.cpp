#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,a[N],ans[N];
int main() {
	int t;cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		for(int m = 1;;++m) {
			int mx = 0,res = -1;
			for(int p = 2;p * p <= 1000;++p) {
				int cnt = 0;
				for(int i = 1;i <= n;++i)
					if(!ans[i] && a[i] % p == 0) ++cnt;
				if(cnt > mx) mx = cnt,res = p;
			}
			if(res == -1) {cout << m-1 << endl;break;}
			for(int i = 1;i <= n;++i)
				if(!ans[i] && a[i] % res == 0) ans[i] = m;
		}
		for(int i = 1;i <= n;++i)
			cout << ans[i] << ' ',ans[i] = 0;
		cout << endl;
	}
	return 0;
}