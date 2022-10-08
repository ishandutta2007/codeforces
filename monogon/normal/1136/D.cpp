
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

int n, m, u, v;
vector<int> p;
set<PII> s;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m;
	p = vector<int>(n);
	FOR(i, n) cin >> p[i];
	int pn = p[n - 1];
	FOR(i, m) {
		cin >> u >> v;
		s.insert(Mp(u, v));
	}
	int i = n - 2;
	while(i >= 0) {
//		cout << p[i] << " " << p[i + 1] << " ";
		auto it = s.find(Mp(p[i], p[i + 1]));
		if(it != s.end()) {
//			cout << "swap";
			swap(p[i], p[i + 1]);
			s.erase(it);
			if(p[i] == pn)
				i--;
			else
				i++;
		}else {
			i--;
		}
//		cout << endl;
	}
	FOR(i, n)
		if(p[i] == pn) {
			cout << (n - i - 1) << endl;
			break;
		}
}