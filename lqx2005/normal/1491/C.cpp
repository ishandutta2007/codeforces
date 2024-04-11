#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
const int N = 1e5 + 10;
int n;
int s[N], fa[N];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }

LL work() {
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	rep(i, 1, n + 1) fa[i] = i;
	LL sum = 0;
	rep(i, 1, n) if(s[i] <= 1) fa[i] = i + 1;
	rep(i, 1, n) {
		int t = max(n - i, 1);
		if(s[i] > t ) sum += s[i] - t, s[i] = t;
		while(s[i] > 1) {
			sum++;
			int now = find(i);
			while(now <= n) {
				s[now]--;
				if(s[now] <= 1) fa[now] = now + 1;
				now = now + s[now] + 1;
				if(now > n) break;
				now = find(now);
			}
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(; T--; ) cout << work() << endl;
	return 0;
}