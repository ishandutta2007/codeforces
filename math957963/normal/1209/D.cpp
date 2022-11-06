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
#define N 200000

vector<int>e[N];

int main() {
	int a[N];
	int xx[N];
	int yy[N];
	bool b[N];
	bool used[N];
	queue<pair<int, int> >q;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d",&k, &n);
	f(i, k)used[i] = false;
	f(i, n)b[i] = false;
	f(i, n) {
		scanf("%d %d", &xx[i],&yy[i]);
		xx[i]--;
		yy[i]--;
		e[xx[i]].push_back(i);
		e[yy[i]].push_back(i);
	}


	f(tt, n) {
		if (!b[tt]) {
			b[tt] = true;
			if ((used[xx[tt]]) && (used[yy[tt]]))ans++;
			else {
				if (!used[xx[tt]]) {
					used[xx[tt]] = true;
					f(i, e[xx[tt]].size()) {
						if ((!b[e[xx[tt]][i]]) && (!used[xx[e[xx[tt]][i]]]))q.push(make_pair(e[xx[tt]][i], xx[e[xx[tt]][i]]));
						if ((!b[e[xx[tt]][i]]) && (!used[yy[e[xx[tt]][i]]]))q.push(make_pair(e[xx[tt]][i], yy[e[xx[tt]][i]]));
					}
				}
				if (!used[yy[tt]]) {
					used[yy[tt]] = true;
					f(i, e[yy[tt]].size()) {
						if ((!b[e[yy[tt]][i]]) && (!used[xx[e[yy[tt]][i]]]))q.push(make_pair(e[yy[tt]][i], xx[e[yy[tt]][i]]));
						if ((!b[e[yy[tt]][i]]) && (!used[yy[e[yy[tt]][i]]]))q.push(make_pair(e[yy[tt]][i], yy[e[yy[tt]][i]]));
					}
				}
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (!b[x]) {
						b[x] = true;
						if (!used[y]) {
							used[y] = true;
							f(i, e[y].size()) {
								if ((!b[e[y][i]]) && (!used[xx[e[y][i]]]))q.push(make_pair(e[y][i], xx[e[y][i]]));
								if ((!b[e[y][i]]) && (!used[yy[e[y][i]]]))q.push(make_pair(e[y][i], yy[e[y][i]]));
							}
						}
						else ans++;
					}
				}
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}