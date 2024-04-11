/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

bool mark[110];
ll f[110];

int main(){
	string s; cin >> s;
	int len = (int)s.size();
	f[0] = 1;
	f[1] = 2;
	for (int i=2; i<=len; i++)
		f[i] = f[i-1] + f[i-2];
	ll ans = 1;
	for (int i=0; i<len; i++) if (!mark[i] && s[i]=='B' && s[(i+1)%len]=='A'){
		mark[i] = mark[(i+1)%len] = true;
		int frw = (i+2)%len;
		int cnt = 1;
		while (!mark[frw] && s[frw]=='B' && s[(frw+1)%len]=='A'){
			cnt++;
			mark[frw] = mark[(frw+1)%len] = true;
			frw = (frw+2)%len;
		}
		int pre = (i-2+len)%len;
		while (!mark[pre] && s[pre]=='B' && s[(pre+1)%len]=='A'){
			cnt++;
			mark[pre] = mark[(pre+1)%len] = true;
			pre = (pre-2+len)%len;
		}
		pre = (pre+1)%len;
		if (cnt * 2 == len){
			if (cnt == 2)
				cout << 3 << endl;
			else
				cout << f[cnt-1] + f[cnt-3] << endl;
			return 0;
		}
		ans = ans * f[max(0,cnt - (s[pre]=='A') - (s[frw]=='B'))]; 
	}
	for (int i=0; i<len; i++) if (len>3 && s[i]=='A' && s[(i+1)%len]=='A' && s[(i+2)%len]=='B' && s[(i+3)%len] == 'B')
		ans = 0;
	cout << ans << endl;
	return 0;
}