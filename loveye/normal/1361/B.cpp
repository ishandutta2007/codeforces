#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5,MOD = 1e9 + 7;
int n,p,k[N],ans,nowp,pos,fac[N] = {1},lim,_,___;
inline long long qpow(long long a,int x) {
	long long res = 1;
	while(x) {
		if(x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1; 
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	int t;cin >> t;
	while(t--) {
		cin >> n >> p;ans = 0;
		for(int i = 1;i <= n;++i)
			cin >> k[i];
		sort(k+1,k+n+1);
		lim = -1;
		for(int i = 1;i <= n;++i) {
			fac[i] = fac[i-1] * p;
			if(fac[i] > n) {
				lim = i;
				break;
			}
		}
		if(lim == -1) lim = k[n]+1;
		nowp = 1;___ = n;
		for(pos = n-1;pos >= 1;--pos) {
			if(nowp) {
				if(k[pos+1] == k[pos]) --nowp;
				else {
					_ = nowp;
					int pw = k[pos+1] - k[pos],now = p;
					for(;pw;now = now * now) {
						if(now > n) {_ = n+1;break;}
						if(pw & 1) _ = _ * now;
						if(_ > n) break;
						pw >>= 1;
					}
					if(_ > n) {
						___ = pos+1;
						while(pos) ans = (ans - qpow(p,k[pos])) % MOD,--pos;
						break;
					}
					else nowp = _-1;
				}
			}
			else ++nowp;
			___ = pos;
		}
		ans = (ans + qpow(p,k[___]) * nowp % MOD) % MOD;
		if(ans < 0) ans = ans + MOD;
		cout << ans << endl;
	}
	return 0;
}