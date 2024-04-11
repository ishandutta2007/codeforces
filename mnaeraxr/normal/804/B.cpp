#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

const int mod = 1000000007;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int ans = 0;
	string s; cin >> s;
	
	int n = (int)s.length();
	int t = 0;

	for (int i = n - 1; i >= 0; --i){
		if (s[i] == 'a'){
			ans += t;
			if (ans >= mod) ans -= mod;
			t <<= 1;
			if (t >= mod) t -= mod;
		}
		else{
			t++;
			if (t == mod) t = 0;
		}
	}
	
	cout << ans << endl;

	return 0;
}