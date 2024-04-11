#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	int n, ss;

	cin >> n >> ss;

	vec< int > b(1e5 + 10), s(1e5 + 10);

	for(int i = 1;i <= n;i++) {
		char ty;
		int p, q;
		cin >> ty >> p >> q;
		if(ty == 'B') b[p] += q;
		else s[p] += q;
	}

	int x = ss;
	vec< int > ans;

	for(int i = 0;i <= 1e5 && x > 0;i++) {
		if(s[i] > 0) {
			ans.push_back(i);
			x--;
		}
	}

	reverse(ALL(ans));

	for(auto i : ans) cout << "S " << i << ' ' << s[i] << '\n';

	x = ss;

	for(int i = 1e5;i >= 0 && x > 0;i--) {
		if(b[i] > 0) {
			cout << "B " << i << ' ' << b[i] << '\n';
			x--;
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}