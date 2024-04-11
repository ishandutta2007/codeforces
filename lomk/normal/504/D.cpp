/*input
7
7
6
5
4
3
2
1
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
// const int N =;

int toInt(char c) {
	return c - '0';
}

char toChar(int c) {
	return c + '0';
}

#ifdef UncleGrandpa
const int lim = 2001;
#else
const int lim = 2001;
#endif
using binary = bitset < lim + 1 >;


const long long base = 1LL << 32;
binary convert(const string &s) {
	vector <long long> v;
	v.push_back(0);
	for (int i = 0; i < s.size(); i += 9) {
		int p10 = 1;
		int val = 0;
		for (int j = 0; j < 9; j++) {
			if (i + j >= s.size()) break;
			val = val * 10 + s[i + j] - '0';
			p10 *= 10;
		}
		for (auto &x : v) x *= p10;
		v[0] += val;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] >= base) {
				if (j + 1 == v.size()) v.push_back(0);
				v[j + 1] += v[j] / base;
				v[j] %= base;
			}
		}
	}
	binary ret;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < 32; j++) {
			if (i * 32 + j >= ret.size()) break;
			ret[i * 32 + j] = v[i] % 2;
			v[i] /= 2;
		}
	}
	return ret;
}

int n;
binary table[lim]; binary need[lim];

pair<binary, bool> findNum(binary form, bool spec = false) {
	binary now, ret;
	rloop(i, lim, 0) {
		if (now[i] != form[i]) {
			if (need[i].count() == 0) return {ret, false};
			ret ^= need[i]; now ^= table[i];
		}
	}
	return {ret, true};
}

void addTable(binary form, int p) {
	binary madeOf; madeOf[p] = 1;
	rloop(i, lim, 0) {
		if (form[i] == 1) {
			if (need[i].count()) {
				form ^= table[i];
				madeOf ^= need[i];
			}
			else {
				table[i] = form;
				need[i] = madeOf;
				break;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	loop(i, 0, n - 1) {
		string s; cin >> s;
		auto form = convert(s);
		auto [rec, can] = findNum(form);
		if (!can) cout << 0 << endl;
		else {
			cout << rec.count() << sp;
			loop(j, 0, lim - 1) if (rec[j]) cout << j << sp;
			cout << endl;
		}
		addTable(form, i);
	}
}