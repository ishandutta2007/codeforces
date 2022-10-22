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

ll n;
char c[500005];
ll x[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n){
		cin >> c[i] >> x[i];
		if(c[i] == '&') x[i] = 1023 - x[i];
	}

	ll A = 0, O = 0, X = 0;
	rep(i, 0, 9){
		ll b[2] = {0, 1};
		rep(j, 1, n){
			if((x[j] & (1<<i)) == 0) continue;
			if(c[j] == '|') b[0] = b[1] = 1;
			if(c[j] == '&') b[0] = b[1] = 0;
			if(c[j] == '^') b[0] = 1-b[0], b[1] = 1-b[1];
		}
		if(b[0] == b[1]){
			if(b[0] == 1) O |= 1<<i;
			else A |= 1<<i;
		}
		else if(b[0] == 1) X |= 1<<i;
	}
	A = 1023 - A;

	cout << 3 << endl;
	cout << "|" << " " << O << endl;
	cout << "&" << " " << A << endl;
	cout << "^" << " " << X << endl;

	return 0;
}