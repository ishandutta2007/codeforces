/*input
2
1 4
5 1


2
1 4
5 1
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

int n;
priority_queue<int> pq[2];
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; pq[0].push(t);
	}
	for (int i = 0; i < n; i++) {
		int t; cin >> t; pq[1].push(t);
	}
	int c = 0;
	int diff = 0;
	while (!pq[0].empty() || !pq[1].empty()) {
		if (pq[0].empty()) {
			if (c == 0) pq[1].pop();
			else diff -= pq[1].top(), pq[1].pop();
		}
		else if (pq[1].empty()) {
			if (c == 1) pq[0].pop();
			else diff += pq[0].top(), pq[0].pop();
		}
		else {
			if (pq[0].top() >= pq[1].top()) {
				if (c == 0)
					diff += pq[0].top(), pq[0].pop();
				else
					pq[0].pop();
			}
			else {
				if (c == 0)
					pq[1].pop();
				else
					diff -= pq[1].top(), pq[1].pop();
			}
		}
		c ^= 1;
	}
	cout << diff << endl;
}