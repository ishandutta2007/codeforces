#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

vec< int > preff(string s) {
	int n = (int)s.size();
	vec< int > p(n);
	for(int i = 1;i < n;i++) {
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) j++;
		p[i] = j;
	}
	return p;
}

bool solve() {

	string a, b, c;

	cin >> a >> b;

	c = a;
	reverse(ALL(c));

	int sa = (int)a.size();
	int sb = (int)b.size();

	set< char > tmp_set;

	for(auto i : a) tmp_set.insert(i);
	for(auto i : b) if(!tmp_set.count(i)) { cout << "-1\n"; return true; }

	vec< pii > lcp1(sb, mp(0, -1)), lcp2(sb, mp(0, -1));

	for(int i = 0;i < sb;i++) {
		string T = b.substr(i) + "#" + a;
		vec< int > p = preff(T);
		int len = sb - i;
		for(int j = len + 1;j < (int)p.size();j++) {
			if(p[j] > lcp1[i].first) {
				lcp1[i] = mp(p[j], j - len - p[j]);
			}
		}
		T = b.substr(i) + "#" + c;
		p = preff(T);
		for(int j = len + 1;j < (int)p.size();j++) {
			if(p[j] > lcp2[i].first) {
				lcp2[i] = mp(p[j], j - len - p[j]);
			}
		}
	}

	vec< int > dp(sb, inf);
	vec< pii > from(sb, mp(-inf, -inf));

	for(int i = 0;i < sb;i++) {
		if(lcp1[0].first >= i + 1) {
			dp[i] = 1;
			from[i] = mp(-1, 1);
		}
		if(lcp2[0].first >= i + 1) {
			dp[i] = 1;
			from[i] = mp(-1, -1);
		}
		for(int j = i;j >= 0;j--) {
			// [j .. i]
			if(lcp1[j].first >= i - j + 1 && dp[i] > (j?dp[j - 1] : 0) + 1) {
				dp[i] = (j?dp[j - 1] : 0) + 1;
				from[i] = mp(j - 1, 1);
			}
			if(lcp2[j].first >= i - j + 1 && dp[i] > (j?dp[j - 1] : 0) + 1) {
				dp[i] = (j?dp[j - 1] : 0) + 1;
				from[i] = mp(j - 1, -1);
			}
		}
	}

	cout << dp[sb - 1] << '\n';

	/*for(int i = 0;i < sb;i++) {
		cout << i << " : " << dp[i] << " " << from[i].first << " " << from[i].second << "\n";
	}*/

	vec< pii > ans;

	for(int i = sb - 1;i >= 0;) {
		int to = from[i].first;
		int left = to + 1;
		int ty = from[i].second;
		if(ty == 1) {
			ans.push_back(mp(lcp1[left].second + 1, lcp1[left].second + 1 + (i - to) - 1 ));
		}else {
			int ql, qr;
			ql = lcp2[left].second + 1;
			qr = ql + (i - to) - 1;
			ql = sa - ql + 1;
			qr = sa - qr + 1;
			ans.push_back(mp(ql, qr));
		}
		i = to;
	}

	reverse(ALL(ans));

	for(auto i : ans) cout << i.first << " " << i.second << "\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}