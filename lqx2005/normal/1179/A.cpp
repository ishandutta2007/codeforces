#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
int n, q;
int A[N], B[N];
deque<int> a;
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		A[i] = a.front();
		a.pop_front();
		B[i] = a.front();
		a.pop_front();
		if(A[i] > B[i]) a.push_front(A[i]), a.push_back(B[i]);
		else a.push_front(B[i]), a.push_back(A[i]); 
	}
	for(int i = 1; i <= q; i++) {
		i64 m;
		scanf("%lld", &m);
		if(m <= n) printf("%d %d\n", A[m], B[m]);
		else {
			int x = (m - n - 1) % (n - 1);
			printf("%d %d\n", a.front(), a[x + 1]);
		}
	}
	return 0;
}