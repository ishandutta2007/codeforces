/*input
6
2 1 4
1 2 4
3 4 4
2 8 3
3 16 3
1 32 2

4
1 1000 1
2 500 2
3 250 3
4 125 4



*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(x) for(int xv=1; xv<=x; xv++)

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
	os << '{';
	for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
		typename set<T>::iterator jt = it;
		os << *it << (++jt != a.end() ? ", " : "");
	}
	os << '}';
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
	os << "{\n";
	for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
		typename map<T1, T2>::iterator jt = it;
		os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
	}
	os << '}';
	return os;
}

int n;
vector<int> price[5][5];
int sz[6];
vector<int> psz[6];
int dp[4][2000005];
int dex[6];

int enc() {
	int ret = 0;
	for (int i = 0; i < 6; i++) {
		ret *= 4;
		ret += dex[i];
	}
	return ret;
}

void dec(int num) {
	for (int i = 5; i >= 0; i--) {
		dex[i] = num % 4;
		num /= 4;
	}
}

bool on(int c) {
	if (c == 0) {
		if (dex[0] || dex[1] || dex[2]) return true;
	}
	if (c == 1) {
		if (dex[0] || dex[3] || dex[4]) return true;
	}
	if (c == 2) {
		if (dex[1] || dex[3] || dex[5]) return true;
	}
	if (c == 3) {
		if (dex[2] || dex[4] || dex[5]) return true;
	}
	return false;
}

class Sup {
private:
	int freeMoney[4][4];
public:
	void init() {
		for (int i = 0; i <= 3; i++) {
			for (int j = i; j <= 3; j++) {
				while (price[i][j].size() >= 4) {
					freeMoney[i][j] += price[i][j].back(); price[i][j].pop_back();
					freeMoney[i][j] += price[i][j].back(); price[i][j].pop_back();
				}
				if (i == j) {
					while (price[i][j].size()) {
						freeMoney[i][j] += price[i][j].back(); price[i][j].pop_back();
					}
				}
			}
		}
	}
	int getFreeMoney(int i, int j) {
		if (i > j) swap(i, j);
		return freeMoney[i][j];
	}
} fr;

// 0 is 0 1
// 1 is 0 2
// 2 is 0 3
// 3 is 1 2
// 4 is 1 3
// 5 is 2 3

int move(int wh, int curColor, int tarColor);
int cal(int curColor, int mask) {
	int &ret = dp[curColor][mask];
	if (ret != -1) return ret;
	ret = 0; int base = 0;
	dec(mask);
	for (int i = 0; i < 4; i++) if (!on(i) && !on(curColor)) base += fr.getFreeMoney(curColor, i);
	if (curColor == 0) {
		ret = max(ret, move(0, 0, 1));
		ret = max(ret, move(1, 0, 2));
		ret = max(ret, move(2, 0, 3));
	}
	else if (curColor == 1) {
		ret = max(ret, move(0, 1, 0));
		ret = max(ret, move(3, 1, 2));
		ret = max(ret, move(4, 1, 3));
	}
	else if (curColor == 2) {
		ret = max(ret, move(1, 2, 0));
		ret = max(ret, move(3, 2, 1));
		ret = max(ret, move(5, 2, 3));
	}
	else {
		ret = max(ret, move(2, 3, 0));
		ret = max(ret, move(4, 3, 1));
		ret = max(ret, move(5, 3, 2));
	}
	return ret + base;
}

int move(int wh, int curColor, int tarColor) {
	if (dex[wh] >= sz[wh]) return 0;
	int tmp[6]; for (int i = 0; i < 6; i++) tmp[i] = dex[i];
	int ret = 0;
	for (int i = 0; i < 4; i++) if (!on(tarColor) && !on(i) && i != curColor) ret += fr.getFreeMoney(tarColor, i);
	dex[wh]++;
	ret += cal(tarColor, enc()) + psz[wh][tmp[wh]];
	for (int i = 0; i < 6; i++) dex[i] = tmp[i];
	return ret;
}

int precal() {
	int ret = 0;
	for (int i = 0; i < 4; i++) ret = max(ret, cal(i, 0));
	return ret;
}


void prep() {
	for (int i = 0; i <= 3; i++) {
		for (int j = i; j <= 3; j++) sort(price[i][j].begin(), price[i][j].end());
	}
	fr.init(); memset(dp, -1, sizeof(dp));
	sz[0] = price[0][1].size();
	sz[1] = price[0][2].size();
	sz[2] = price[0][3].size();
	sz[3] = price[1][2].size();
	sz[4] = price[1][3].size();
	sz[5] = price[2][3].size();
	for (auto it : price[0][1])
		psz[0].push_back(it);
	for (auto it : price[0][2])
		psz[1].push_back(it);
	for (auto it : price[0][3])
		psz[2].push_back(it);
	for (auto it : price[1][2])
		psz[3].push_back(it);
	for (auto it : price[1][3])
		psz[4].push_back(it);
	for (auto it : price[2][3])
		psz[5].push_back(it);
	for (int i = 0; i < 6; i++) sort(psz[i].begin(), psz[i].end(), greater<int>());
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef in1code
	freopen("1test.inp", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, c, v;
		cin >> u >> c >> v;
		u--; v--;
		if (u > v) swap(u, v);
		price[u][v].push_back(c);
	}
	prep();
	cout << precal() << endl;
}