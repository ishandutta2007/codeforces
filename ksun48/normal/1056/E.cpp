#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long H;
static const H M = INT_MAX;
static H C; // initialized below

// Arithmetic mod M. "typedef H K;" instead if you think
// test data is random. (Haha, good luck.)
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};

struct HashInterval {
	vector<K> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	K h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h - 0};
	ret.reserve(sz(str) - length + 1);
	rep(i,length,sz(str)) {
		ret.push_back(h * C + str[i] - pw * str[i-length]);
		h = ret.back();
	}
	return ret;
}

H hashString(string& s) {
	K h = 0;
	trav(c, s) h = h * C + c;
	return h - 0;
}

#include <sys/time.h>
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	timeval tp;
	gettimeofday(&tp, 0);
	C = tp.tv_usec;


	string s;
	string t;
	cin >> s >> t;

	int f0 = 0;
	int f1 = 0;
	for(char a : s){
		if(a == '0') f0++;
		if(a == '1') f1++;
	}
	HashInterval hash(t);
	int n = t.size();
	int ans = 0;
	for(int l0 = 1; l0 * f0 <= n; l0++){
		int l1 = (n - f0 * l0) / f1;
		if(f0 * l0 + f1 * l1 != n) continue;
		if(l1 <= 0) continue;
		vector<H> hlist[2];
		int len = 0;
		for(char a : s){
			int newlen;
			if(a == '0') newlen = len + l0;
			if(a == '1') newlen = len + l1;
			H h = hash.hashInterval(len, newlen);
			hlist[a - '0'].push_back(h);
			len = newlen;
		}
		assert(len == n);
		int ok = 1;
		for(int b = 0; b < 2; b++){
			for(H r : hlist[b]){
				if(r != hlist[b][0]){
					ok = 0;
				}
			}
		}
		if(hlist[0][0] == hlist[1][0]) ok = 0;
		ans += ok;
	}
	cout << ans << '\n';
}