#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 100 + 10;
int a[N], b[N];
void solve() {
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	for(int i = n; i >= 1; i--) {
		if(a[i] > b[i]) {
			printf("NO\n");
			return;
		}
		if(a[i] < b[i] - 1) {
			printf("NO\n");
			return;
		}
	} 
	printf("YES\n");
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}