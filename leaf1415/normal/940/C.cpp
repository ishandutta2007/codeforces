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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
string s, S;
int a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s;
	S = s;
	sort(all(S));
	S.erase(unique(all(S)), S.end());

	ll m = S.size();
	if(k > n){
		rep(i, 1, k-n) s += S[0];
		cout << s << endl;
		return 0;
	}

	s.resize(k);
	rep(i, 0, k-1) a[i] = lower_bound(S.begin(), S.end(), s[i]) - S.begin();
	a[k-1]++;
	for(int i = k-1; i >= 0; i--){
		if(a[i] >= m) a[i] = 0, a[i-1]++;
		else break;
	}

	rep(i, 0, k-1) cout << S[a[i]];
	cout << endl;

	return 0;
}