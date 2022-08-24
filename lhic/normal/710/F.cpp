#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

struct node {
	int go[26];
	int pc;
	int p;
	int sf;
	ll dp;
	node(int P, int PC) {
		fill(go, go + 26, -1);
		p = P;
		pc = PC;
		sf = 0;
		dp = 0;
	}
};

queue<int> qu;

struct ak {
	vector<string> vv;
	vector<node> nd;
	void add(const string &s) {
		int now = 0;
		for (int i = 0; i < s.size(); ++i) {
			int x = s[i] - 'a';
			if (nd[now].go[x] != -1)
				now = nd[now].go[x];
			else {
				nd[now].go[x] = nd.size();
				nd.push_back(node(now, x));
				now = nd[now].go[x];
			}
		}
		nd[now].dp += 1;
	}
	void build_ak() {
		nd.push_back(node(-1, -1));
		for (int i = 0; i < vv.size(); ++i)
			add(vv[i]);
		qu.push(0);
		while (!qu.empty()) {
			int x = qu.front();
			qu.pop();
			for (int i = 0; i < 26; ++i)
				if (nd[x].go[i] != -1)
					qu.push(nd[x].go[i]);
			if (x == 0) {
				for (int i = 0; i < 26; ++i)
					if (nd[x].go[i] == -1)
						nd[x].go[i] = 0;
				continue;
			}
			if (nd[x].p == 0)
				nd[x].sf = 0;
			else
				nd[x].sf = nd[nd[nd[x].p].sf].go[nd[x].pc];
			for (int i = 0; i < 26; ++i) {
				if (nd[x].go[i] == -1)
					nd[x].go[i] = nd[nd[x].sf].go[i];
			}
			nd[x].dp += nd[nd[x].sf].dp;
		}
	}
	ll fnd(const string &s) {
		int now = 0;
		ll ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			now = nd[now].go[s[i] - 'a'];
			ans += nd[now].dp;
		}
		return ans;
	}
	void clear() {
		nd.clear();
		vv.clear();
	}
};

const int LG = 19;

ak ad[LG];
ak dl[LG];

int m;
char buf[310000];
vector<string> vv;
string s;

int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int t;
		scanf("%d %s", &t, buf);
		s = buf;
		if (t == 1) {
			vv.clear();
			vv.push_back(s);
			for (int i = 0; i < LG; ++i) {
				if (!ad[i].vv.empty()) {
					for (int j = 0; j < (int)ad[i].vv.size(); ++j)
						vv.push_back(ad[i].vv[j]);
					ad[i].vv.clear();
					ad[i].clear();
				}
				else {
					swap(vv, ad[i].vv);
					ad[i].build_ak();
					break;
				}
			}
		}
		else if (t == 2) {
			vv.clear();
			vv.push_back(s);
			for (int i = 0; i < LG; ++i) {
				if (!dl[i].vv.empty()) {
					for (int j = 0; j < (int)dl[i].vv.size(); ++j)
						vv.push_back(dl[i].vv[j]);
					dl[i].vv.clear();
					dl[i].clear();
				}
				else {
					swap(vv, dl[i].vv);
					dl[i].build_ak();
					break;
				}
			}
		}
		else {
			ll ans = 0;
			for (int i = 0; i < LG; ++i)
				if (ad[i].vv.size())
					ans += ad[i].fnd(s);
			for (int i = 0; i < LG; ++i)
				if (dl[i].vv.size())
					ans -= dl[i].fnd(s);
			printf("%lld\n", ans);
			fflush(stdout);
		}
	}
	return 0;
}