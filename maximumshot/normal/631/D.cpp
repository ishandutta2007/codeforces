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
#include <bitset>

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

const int mod = inf + 7;

bool solve() {
	
	int n, m;
	scanf("%d %d", &n, &m);

	vec< pair< int, char > > tt(n), ss(m);
	vec< pair< ll, char > > t, s;

	for(int i = 0;i < n;i++) {
		int l;
		char c;
		scanf("%d-%c", &l, &c);
		tt[i] = mp(l, c);
	}

	for(int i = 0;i < m;i++) {
		int l;
		char c;
		scanf("%d-%c", &l, &c);
		ss[i] = mp(l, c);
	}

	for(int i = 0;i < n;i++) {
		int j = i;
		ll sum = 0;
		while(j < n && tt[i].second == tt[j].second) sum += tt[j++].first;
		t.push_back(mp(sum, tt[i].second));
		i = j - 1;
	}

	tt.clear();

	for(int i = 0;i < m;i++) {
		int j = i;
		ll sum = 0;
		while(j < m && ss[i].second == ss[j].second) sum += ss[j++].first;
		s.push_back(mp(sum, ss[i].second));
		i = j - 1;
	}

	ss.clear();

	if((int)s.size() == 1) {
		ll ans = 0;
		for(int i = 0;i < (int)t.size();i++) {
			if(t[i].second == s[0].second && t[i].first >= s[0].first) {
				ans += t[i].first - s[0].first + 1;
			}
		}
		cout << ans << '\n';
	}else if((int)s.size() == 2) {
		int ans = 0;
		for(int i = 0;i + 1 < (int)t.size();i++) {
			if(t[i].second == s[0].second && t[i + 1].second == s[1].second && 
				t[i].first >= s[0].first && t[i + 1].first >= s[1].first) ans++;
		}
		cout << ans << '\n';
	}else {
		int sz = (int)s.size() - 2 + 1 + (int)t.size();
		int len = (int)s.size() - 2;
		int ans = 0;
		vec< int > p(sz);
		for(int i = 1;i < sz;i++) {
			int j = p[i - 1];
			while(j > 0 && (i < len?s[i + 1] : (i == len?mp(-1ll, '0') : t[i - len - 1])) != (j < len?s[j + 1] : (j == len?mp(-1ll, '0') : t[j - len - 1])) ) j = p[j - 1];
			if((i < len?s[i + 1] : (i == len?mp(-1ll, '0') : t[i - len - 1])) == (j < len?s[j + 1] : (j == len?mp(-1ll, '0') : t[j - len - 1]))) j++;
			p[i] = j;
		}
		for(int i = 0;i < (int)t.size();i++) {
			if(t[i].second == s[0].second && t[i].first >= s[0].first) {
				int _end = i + len;
				if(_end >= (int)t.size()) break;
				if(p[len + 1 + _end] >= len) {
					if(_end + 1 < (int)t.size()) {
						_end++;
						if(t[_end].second == s.back().second && t[_end].first >= s.back().first) ans++;
					}
				}
			}	
		}
		cout << ans << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}