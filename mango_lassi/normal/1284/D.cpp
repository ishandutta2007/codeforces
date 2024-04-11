#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Itv {
	int a1, a2;
	int b1, b2;

	bool operator<(const Itv& rhs) const { return a1 < rhs.a1; }
};

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		T get(int a, int b) const {
			T res = seg[a + n]; // Change to INF to allow a > b
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
};


// Find last interval with a1 <= a
int bins(const vector<Itv>& vec, int a) {
	int low = -1;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		if (vec[mid].a1 <= a) low = mid;
		else high = mid - 1;
	}
	return low;
}

// Check if some two overlap in a's, but do not overlap in b's.
// All in range overlap if latest start <= vec[i].b2 and earliest end >= vec[i].b1
bool check(vector<Itv> vec) {
	int n = vec.size();
	sort(vec.begin(), vec.end());

	vector<int> b1s(n), b2s(n);
	for (int i = 0; i < n; ++i) {
		b1s[i] = -vec[i].b1;
		b2s[i] = vec[i].b2;
	}
	RangeMin<int> starts(b1s), ends(b2s);

	for (int x = 0; x < n; ++x) {
		int y = bins(vec, vec[x].a2);
		if (-starts.get(x, y) > vec[x].b2) return true; // latest start > vec[i].b2
		if (ends.get(x, y) < vec[x].b1) return true; // earliest end < vec[i].b1
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Itv> itvs(n);
	for (auto& itv : itvs) cin >> itv.a1 >> itv.a2 >> itv.b1 >> itv.b2;

	// Set s is impossible IFF some two intervals in it overlap
	// -> Always exists venue-sensitive set of size two if any venue-sensitive sets exist

	bool vs = false;
	vs |= check(itvs);
	for (auto& itv : itvs) {
		swap(itv.a1, itv.b1);
		swap(itv.a2, itv.b2);
	}
	vs |= check(itvs);

	if (vs) cout << "NO\n";
	else cout << "YES\n";
}