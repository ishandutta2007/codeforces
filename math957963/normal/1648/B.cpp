#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int s[N]; 
	int t, n, c, x, y;
	bool ans;
	cin >> t;
	rep(tt, t) {
		ans = true;
		cin >> n >> c;
		rep(i, c + 2)s[i] = 0;
		rep(i, n) {
			cin >> x;
			s[x + 1]++;
		}
		rep(i, c + 1)s[i + 1] += s[i];
		if (s[2] == 0) {
			cout << "No" << endl;
			continue;
		}
		rep2(i,2,c){
            if(i>(c/2))break;
			if (s[i] < s[i + 1]) {
				rep2(j, 2, c / i) {
					if (s[j] == s[j + 1])if (s[j*i] < s[min((j + 1)*i, c + 1)])ans = false;
				}
			}
		}
		if (ans)cout << "Yes" << endl;
		else cout << "No" << endl;
	}


	return 0;
}