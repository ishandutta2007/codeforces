#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// Binary search. Assumes vec is sorted
// res := number of elements strictly smaller than v in vec
// Complexity: O(log n), where n = vec.size()
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

// Coordinate Compression
// res[i] := number of unique elements in vec strictly smaller than vec[i]
// Complexity: O(n log n), where n = vec.size()
template<class T>
vector<int> compress(const vector<T>& vec) {
	vector<T> coll = vec;
	sort(coll.begin(), coll.end());
	coll.erase(unique(coll.begin(), coll.end()), coll.end());

	vector<int> res(vec.size());
	for (int i = 0; i < vec.size(); ++i) res[i] = bins(coll, vec[i]);
	return res;
}

const int N = 10 + 2 * (int)1e5;
int fenw[N+1];
int vals[N+1];

void fenwAdd(int i) {
	++i;
	while(i <= N) {
		fenw[i] += 1;
		i += (i & -i);
	}
}
int fenwSum(int i) {
	++i;
	int res = 0;
	while(i > 0) {
		res += fenw[i];
		i -= (i & -i);
	}
	return res;
}
int fenwRangeSum(int a, int b) {
	return fenwSum(b) - fenwSum(a-1);
}
ll chooseTwo(ll cou) {
	return cou * (cou+1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Q: How many sets have point with y=h as their bottommost point?
	// A: (number of different x's choose 2) - number of ways to pick different x's s.t. no y gets picked

	// We need a set that supports counting number of elements in some interval, and inserting points

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i) {
		cin >> pts[i].second >> pts[i].first;
	}
	sort(pts.begin(), pts.end());
	reverse(pts.begin(), pts.end());

	vector<int> xs(n), ys(n);
	for (int i = 0; i < n; ++i) {
		xs[i] = pts[i].second;
		ys[i] = pts[i].first;
	}
	xs = compress(xs);

	int j = 0;
	ll res = 0;
	while(j < n) {
		int jj = j;
		while((jj < n) && (ys[jj] == ys[j])) ++jj;

		vector<int> adds = {-1};
		for (int i = j; i < jj; ++i) adds.push_back(xs[i]);
		adds.push_back(n);
		sort(adds.begin(), adds.end());

		ll cont = 0;
		for (int i = 0; i+1 < adds.size(); ++i) {
			cont -= chooseTwo(fenwRangeSum(adds[i]+1, adds[i+1]-1));
		}
		for (auto v : adds) {
			if (0 <= v && v < n && vals[v] == 0) {
				++vals[v];
				fenwAdd(v);
			}
		}
		cont += chooseTwo(fenwRangeSum(0, n-1));
		res += cont;

		j = jj;
	}
	cout << res << '\n';
}