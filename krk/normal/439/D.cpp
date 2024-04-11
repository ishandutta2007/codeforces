#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

int n, m;
map <int, int> A, B;
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		A[a]++;
	}
	for (int i = 0; i < m; i++) {
		int b; scanf("%d", &b);
		B[b]++;
	}
	while (A.begin()->first < B.rbegin()->first)
		if (A.begin()->second <= B.rbegin()->second) {
			map <int, int>::iterator it = A.begin(); it++;
			if (it == A.end()) { res += ll(A.begin()->second) * (B.rbegin()->first - A.begin()->first); break; }
			else {
				int mn = min(B.rbegin()->first, it->first);
				res += ll(A.begin()->second) * (mn - A.begin()->first);
				it->second += A.begin()->second;
				A.erase(A.begin());
			}
		} else {
			map <int, int>::iterator it = B.end(); it--;
			map <int, int>::iterator it2 = it; it2--;
			if (it == B.begin()) { res += ll(it->second) * (it->first - A.begin()->first); break; }
			else {
				int mx = max(A.begin()->first, it2->first);
				res += ll(it->second) * (it->first - mx);
				it2->second += it->second;
				B.erase(it);
			}
		}
	printf("%I64d\n", res);
	return 0;
}