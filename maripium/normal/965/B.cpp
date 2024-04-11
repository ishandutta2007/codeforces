#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k;
char c[N][N];
int f[N][N];

int calc(int x,int y) {
	if (c[x][y] == 0) return 0;
	int ret = 0;
	for (int i = max(1,x - k + 1);i <= x;++i) {
		bool flag = true;
		for (int j = i;j <= i + k - 1;++j) {
			if (j > n || c[j][y] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) ++ret;
	}
	
	for (int i = max(1,y - k + 1);i <= y;++i) {
		bool flag = true;
		for (int j = i;j <= i + k - 1;++j) {
			if (j > n || c[x][j] == '#') {
				flag = false;
				break;
			}
		}
		if(flag) ++ret;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;++i)
		for (int j = 1;j <= n;++j)	
			cin >> c[i][j];
	int x = 1,y = 1, res = calc(1,1);
	for (int i = 1;i <= n;++i)  {
		for (int j = 1;j <= n;++j) {
			int tmp = calc(i,j);
			if (tmp > res) {
				res = tmp;
				x = i;
				y = j;
			}
		}
	}
	cout << x << ' ' << y;
}