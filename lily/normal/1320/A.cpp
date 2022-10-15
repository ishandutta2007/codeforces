#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 202255

int n;
int a[N];
map <int, long long> ans;
int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), a[i] -= i;
	for (int i = 1; i <= n; i++) ans[a[i]] += a[i] + i;
	long long aa = 0;
	for (int i = 1; i <= n; i++) aa = max(aa, ans[a[i]]);
	cout << aa << endl;
}