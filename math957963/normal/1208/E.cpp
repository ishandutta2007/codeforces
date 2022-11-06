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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 1000100


int main() {
	vector<long long> a[N];
	priority_queue<pair<long long, long long> > pq;
	long long b[N];
	f(i, N)b[i] = 0;
	long long pre;
	long long n, k, m;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d", &n, &m);
	f(i, n) {
		scanf("%I64d", &k);
		f(j, k) {
			scanf("%I64d", &x);
			a[i].push_back(x);
		}
	}
	f(i, n) {
		if ((a[i].size() * 2) <= m) {
			pre = 0;
			f(j, a[i].size()) {
				x = max(pre, a[i][j]);
					b[j] += (x - pre);
					pre = x;
			}
			pre = 0;
			z = a[i].size();
			f(j, a[i].size()) {
				x = max(pre, a[i][z - j - 1]);
					b[m - j] -= (x - pre);
					pre = x;
			}
		}
		else {
			pre = 0;
			z = a[i].size();
			while (!pq.empty())pq.pop();
			pq.push(make_pair(0, -1));
			f(j, m) {
				if(j<z)pq.push(make_pair(a[i][j], j));
				else if(j==z)pq.push(make_pair(0, z));
				x = pq.top().second;
				while (x < j - (m - z)) {
					pq.pop();
					x = pq.top().second;
				}
				x = pq.top().first;
				b[j] += (x - pre);
				pre = x;
			}
		}
	}
	ans = 0;
	f(i, m) {
		ans += b[i];
		printf("%I64d", ans);
		if (i < (m - 1))printf(" ");
		else printf("\n");
	}


	return 0;
}