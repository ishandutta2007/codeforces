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

int n, t, ans, M;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		M = 0;
		cin >> n;
		FOR(k, 9) {
			set<int> s1, s2;
			FOR(i, n) {
				if(((i + 1) >> k) & 1) {
					s1.insert(i + 1);
				}else s2.insert(i + 1);
			}
			if(s1.size() == 0 || s2.size() == 0) break;
			cout << s1.size() << " " << s2.size() << " ";
			for(int a : s1) cout << a << " ";
			for(int b : s2) cout << b << " ";
			cout << endl << flush;
			cin >> ans;
			if(ans == -1) exit(0);
			M = max(M, ans);
		}
		cout << "-1 " << M << endl << flush;
	}
}