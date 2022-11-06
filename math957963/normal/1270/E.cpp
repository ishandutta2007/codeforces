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


int main() {
	vector<pair<pair<int, int>,int> >p;
	vector<int>b;
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d", &x, &y);
		p.push_back(make_pair(make_pair(x, y), i + 1));
	}
	while (true) {
		x = 0;
		y = 0;
		f(i, n) {
			if (abs(p[i].first.first) % 2 == 0)x++;
			else y++;
		}
		if ((x > 0) && (y > 0))break;
		if (x == 0) {
			f(i, n)(p[i].first.first)++;
		}
		x = 0;
		y = 0;
		f(i, n) {
			if (abs(p[i].first.second) % 2 == 0)x++;
			else y++;
		}
		if ((x > 0) && (y > 0))break;
		if (x == 0) {
			f(i, n)(p[i].first.second)++;
		}
		f(i, n) {
			p[i].first.first /= 2;
			p[i].first.second /= 2;
		}
		
	}

		x = 0;
		y = 0;
		b.clear();
		f(i, n) {
			z = p[i].first.first;
			z += (p[i].first.second);
			z = abs(z);
			if (z % 2 == 0) {
				x++;
				b.push_back(p[i].second);
			}
			else y++;
		}
		if ((x > 0) && (y > 0)) {
			printf("%d\n", x);
			f(i, b.size()) {
				printf("%d", b[i]);
				if (i < (b.size() - 1))printf(" ");
				else printf("\n");
			}
			return 0;
		}
		x = 0;
		b.clear();
		f(i, n) {
			if (abs(p[i].first.first) % 2 == 0) {
				x++;
				b.push_back(p[i].second);
			}
		}
		printf("%d\n", x);
		f(i, b.size()) {
			printf("%d", b[i]);
			if (i < (b.size() - 1))printf(" ");
			else printf("\n");
		}

	return 0;
}