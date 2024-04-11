/*input
4
4
2
72
10

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
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

#define M 105
int primes[M];
void eratosthene() {
	for (int i = 2; i <= M - 5; i++) if (primes[i] == 0) for (int j = i; j <= M - 5; j += i) primes[j] = i;
}
int cnt[M]; bool pass[M];
int n;
int lim[M];
const int INF = 1e18;
const double lINF = log(4 * INF);
int cached[105][64];
#define pow binPow
long long binPow(long long a, long long q) {
	if (a < 105 && q < 64) {
		if (cached[a][q] != 0) return cached[a][q];
		long long &ret = cached[a][q];
		ret = 1;
		for (int i = 0; (1LL << i) <= q; i++) {
			if (q & (1LL << i)) ret = (ret * a);
			a = (a * a);
		}
		return ret;
	}
	long long ret = 1;
	for (int i = 0; (1LL << i) <= q; i++) {
		if (q & (1LL << i)) ret = (ret * a);
		a = (a * a);
	}
	return ret;
}

bool smaller(int a, int q, int num) {
	if (log(a)*q >= lINF) return false;
	if (binPow(a, q) > num) return false;
	return true;
}

void prep() {
	eratosthene();
	for (int i = 2; i <= 63; i++) {
		int num = i;
		while (num != 1) {
			int val = primes[num]; cnt[i]++;
			int con = 0;
			while (primes[num] == val)
				num /= val, con++;
			if (con > 1) pass[i] = true;
		}
	}
	for (int i = 1; i <= 63; i++) {
		if (pass[i]) continue;
		int lo = 1, hi = 1e18;
		while (lo != hi) {
			int mid = (lo + hi + 1) / 2;
			if (smaller(mid, i, INF) == true) lo = mid;
			else hi = mid - 1;
		}
		lim[i] = hi;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	prep();
	int T; cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= 63; i++) {
			if (pass[i]) continue;
			int lo = 1, hi = lim[i];
			while (lo != hi) {
				int mid = (lo + hi + 1) / 2;
				if (smaller(mid, i, n) == true) lo = mid;
				else hi = mid - 1;
			}
			hi--;
			if (cnt[i] & 1) ans -= hi;
			else ans += hi;
		}
		cout << ans << endl;
	}

}