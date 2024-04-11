/*input
10
78 31 22 16
58 8 58 44
24 59 49 40
97 77 39 24
8 2 33 83
96 11 66 59
20 38 47 76
8 5 47 97
19 71 82 36
91 29 95 95



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

struct data {
	pair<int, int> sta, end;
	data(pair<int, int> _sta, pair<int, int> _end): sta(_sta), end(_end) {
		if (sta.fi > end.fi) swap(sta, end);
	};
};

int n;
vector<data> line;

// const int INF = -1e9;
int ans = 0;

#define Point pair<int,int>
#define X fi
#define Y se
int ccw(Point p, Point q, Point r) {
	int val = (q.Y - p.Y) * (r.X - q.X) -
	          (q.X - p.X) * (r.Y - q.Y);

	if (val == 0) return 0;

	return (val > 0) ? 1 : 2;
}

int gcd(int a , int b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		line.push_back(data(mp(ax, ay), mp(bx, by)));
		if (ax == bx)
			ans += abs(by - ay) + 1;
		else if (ay == by)
			ans += abs(bx - ax) + 1;
		else
			ans += abs(gcd(ax - bx, by - ay)) + 1;
	}
	for (int i = 0; i < n; i++) {
		set<pair<int, int> > st;
		for (int j = i + 1; j < n; j++) {
			auto p1 = line[i].sta; auto q1 = line[i].end;
			auto p2 = line[j].sta; auto q2 = line[j].end;
			if (ccw(p1, p2, q1) == ccw(p1, q2, q1) || ccw(p2, p1, q2) == ccw(p2, q1, q2)) continue;
			int up =  -1 * ((p1.X - q1.X) * (p2.X * q2.Y - q2.X * p2.Y) - (q2.X - p2.X) * (q1.X * p1.Y - p1.X * q1.Y));
			int down = ((p2.Y - q2.Y) * (p1.X - q1.X) - (q2.X - p2.X) * (q1.Y - p1.Y));
			if (up % down != 0) continue;
			int X = up / down;
			up = -1 * (p2.X * q2.Y * p1.Y - p2.X * q2.Y * q1.Y - q2.X * p2.Y * p1.Y + q2.X * p2.Y * q1.Y - p2.Y * p1.X * q1.Y + p2.Y * q1.X * p1.Y + q2.Y * p1.X * q1.Y - q2.Y * q1.X * p1.Y);
			down = (-1 * p2.X * p1.Y + p2.X * q1.Y + q2.X * p1.Y - q2.X * q1.Y + p2.Y * p1.X - p2.Y * q1.X - q2.Y * p1.X + q2.Y * q1.X);
			if (up % down != 0) continue;
			int Y = up / down;
			st.insert(mp(X, Y));
		}
		ans -= st.size(); st.clear();
	}
	cout << ans << endl;
}