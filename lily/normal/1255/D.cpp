#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 105

int n, m, K;
char s[N][N];
vector <char> C;
vector < pair<int, int> > a;
void work() {
	read(n); read(m); read(K);
	a.clear();
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= m; j++) {
				a.push_back({i, j});
			}
		}
		else {
			for (int j = m; j ; j--) {
				a.push_back({i, j});
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {

		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) cnt += s[i][j] == 'R';
	}
	vector <int> b;
	int B = 0;
	for (int i = K; i; i--) {
		auto x = cnt / i;
		cnt -= x;
		if (x)
		b.push_back(x);
		else B++;
	}
	int val = 0, c = 0;
	for (auto v : a) {
		if (val == 0 && B) {
			s[v.first][v.second] = C[62 - B];
			B--;
		}
		else {
			val += s[v.first][v.second] == 'R';
			s[v.first][v.second] = C[c];
			if (val == b[c]) {
				if (c + 1 < b.size()) c++, val = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) puts(s[i] + 1);
}

int main() {
	for (int i = 'a'; i <= 'z'; i++) C.push_back(i);
	for (int i = 'A'; i <= 'Z'; i++) C.push_back(i);
	for (int i = '0'; i <= '9'; i++) C.push_back(i);
	int T;
	read(T);
	while (T--) work();
}