#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

// Returns true if a*b < c*d
bool compare(ld a, ld b, ld c, ld d) {
	return a*b < c*d;
}

// Lines of type ax + b
template<class T1, class T2 = T1>
struct Line {
	T1 a, b;
	ll i;

	T2 eval(T2 x) { return (T2)a*x + b; }
	bool redundant(Line le, Line ri) {
		if (le.a == ri.a) return (b > min(le.b, ri.b)) || (le.b == b && b == ri.b);
		return compare(le.b - ri.b, le.a - a, le.b - b, le.a - ri.a);
	}
};
template<class T1, class T2 = T1>
struct ConvHull {
	vector<Line<T1, T2>> lines;

	void addLine(Line<T1, T2> li) {
		int n = lines.size();
		for (; n && lines[n-1].redundant(lines[max(0, n-2)], li); --n) {
			lines.pop_back();
		}
		if (n == 0 || (! li.redundant(lines[n-1], li))) lines.push_back(li);
	}
	Line<T1, T2> getLine(T2 x) {
		int low = 0;
		int high = (int)lines.size() - 1;
		while(low < high) {
			int mid = (low + high) >> 1;
			if (lines[mid].eval(x) <= lines[mid+1].eval(x)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return lines[low];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	int q;
	cin >> n >> q;

	ll b = 0;
	ll s = 0;
	ConvHull<ll, ll> lines;
	lines.addLine({0, 0, 1});

	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int k;
			cin >> k;
			lines.lines.clear();
			lines.addLine({0, -((ll)s*0 + b), 1});
			n += k;
		} else if (t == 2) {
			int k;
			cin >> k;
			lines.addLine({n, -((ll)s*n + b), n+1});
			n += k;
		} else {
			int bp, sp;
			cin >> bp >> sp;
			b += bp;
			s += sp;
		}
		auto line = lines.getLine(s);
		cout << line.i << ' ' << line.eval(s) + b << '\n';
	}
}