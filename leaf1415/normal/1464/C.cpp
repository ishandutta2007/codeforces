#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, T;
ll cnt[40];
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> T;
	cin >> s;
	reverse(all(s));
	
	T -= 1LL<<(s[0]-'a');
	T += 1LL<<(s[1]-'a');
	T = abs(T);
	
	rep(i, 2, (int)s.size()-1) cnt[s[i]-'a']++;
	rep(i, 0, 35) T += (1LL<<i) * cnt[i];
	
	for(int i = 35; i >= 0; i--){
		ll x = min(cnt[i], T/(1LL<<(i+1)));
		T -= x * (1LL<<(i+1));
	}
	if(T == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}