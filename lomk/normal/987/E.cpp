/*input
10
4 10 5 3 7 8 2 1 9 6

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 1000005
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

int a[N];
int tree[N];

int get(int i) {
	int ret = 0;
	for (; i <= N - 5; i += i & -i) ret += tree[i];
	return ret;
}

void update(int i, int val) {
	for (; i; i -= i & -i) tree[i] += val;
	return;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long buf = 0;
	for (int i = 1; i <= n; i++) {
		buf += get(a[i] + 1);
		update(a[i], 1);
	}
	if (buf % 2 == n % 2) cout << "Petr" << endl;
	else cout << "Um_nik" << endl;
}