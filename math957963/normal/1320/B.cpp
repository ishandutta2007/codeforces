#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 300000

vector<int>e[N];
bool used[N];
queue<int>q;
int d[N];
int b[N];


int main() {
	vector<int>a;
	int n, m,k;
	int st, go;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, m) {
		scanf("%d %d", &x, &y);
		e[y - 1].push_back(x - 1);
	}
	scanf("%d", &k);
	f(i, k) {
		scanf("%d", &x);
		a.push_back(x - 1);
	}
	go = a[0];
	st = a[k - 1];
	f(i, N)used[i] = false;
	d[st] = 0;
	q.push(st);
	used[st] = true;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		f(i, e[x].size()) {
			if (!used[e[x][i]]) {
				used[e[x][i]] = true;
				d[e[x][i]] = d[x] + 1;
				q.push(e[x][i]);
			}
		}
	}
	f(i, N)b[i] = 0;
	f(i, n) {
		f(j, e[i].size()) {
			if (d[e[i][j]] == d[i] + 1)b[e[i][j]]++;
		}
	}
	x = 0;
	y = 0;
	f(i, k - 1) {
		if (d[a[k - i - 2]] != (d[a[k - i - 1]] + 1)) {
			x++;
			y++;
		}
		else if (b[a[k - i - 2]] > 1)y++;
	}

	printf("%d %d\n", x, y);


	return 0;
}