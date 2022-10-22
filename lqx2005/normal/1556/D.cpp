#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e4 + 10;
int a[N], id[N];

int asksum(int i, int j) {
	cout << "or " << i <<" " << j << endl;
	int num, sum = 0;
	cin >> num, sum += num;
	cout << "and " << i <<" " << j << endl;
	cin >> num, sum += num;
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) id[i] = i;
	for(int i = 2; i <= n; i++) {
		a[i] = asksum(1, i);
	}
	i64 a2 = 0;
	a2 -= a[3];
	a2 += a[2];
	for(int i = 3; i <= n; i++) {
		a[i] -= a[2];
	}
	int tmp = asksum(2, 3);
	a2 += tmp;
	a2 /= 2;
	a[1] = a[2] - tmp + a[3];
	a[2] = 0;
	sort(id + 1, id + n + 1, [&](int x, int y) {
		return a[x] < a[y];
	});
	cout << "finish " << a[id[k]] + a2 << endl;
	return 0; 
}