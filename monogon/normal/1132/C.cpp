#include <iostream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long

using namespace std;

int n, q, l, r;
int painted[5005], byone[5005], bytwo[5005];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n >> q;
	vector<PII> vec;
	FOR(i, q) {
		cin >> l >> r;
		vec.push_back(Mp(l, r));
		FORK(i, l, r + 1) {
			painted[i]++;
		}
	}
	sort(all(vec));
	byone[0] = 0;
	bytwo[0] = 0;
	FORK(i, 1, n + 1) {
		byone[i] = byone[i - 1] + (painted[i] == 1 ? 1 : 0);
		bytwo[i] = bytwo[i - 1] + (painted[i] == 2 ? 1 : 0);
	}
//	FOR(i, n + 1) {
//		cout << byone[i] << " ";
//	}
//	cout << endl;
	int M = n + 5;
	FOR(i, q) {
		FORK(j, i + 1, q) {
			int removed = byone[vec[i].second] - byone[vec[i].first - 1]
						+ byone[vec[j].second] - byone[vec[j].first - 1];
			if(vec[i].second < vec[j].first) {
				// nonoverlapping
//				cout << "Case 1: ";
			}else if(vec[i].second < vec[j].second) {
				removed += (bytwo[vec[i].second] - bytwo[vec[j].first - 1]) - (byone[vec[i].second] - byone[vec[j].first - 1]);
//				cout << "Case 2: ";
			}else {
				removed += (bytwo[vec[j].second] - bytwo[vec[j].first - 1]) - (byone[vec[j].second] - byone[vec[j].first - 1]);
//				cout << "Case 3: ";
			}
//			cout << i << " " << j << " " << removed << endl;
			M = min(M, removed);
		}
	}
	int sum = 0;
	FOR(i, n + 1) sum += (painted[i] >= 1);
	cout << sum - M << endl;
}