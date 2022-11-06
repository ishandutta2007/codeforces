#pragma GCC optimize("O3")
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
#define N 300010


int main() {
	int n;
	int k;
	int ans;
	int maxk;
	int s;
	int sz;
	bool fin[N];
	bool a[N];
	vector<int>ch;
	f(i, N) {
		a[i] = false;
		fin[i] = false;
	}
	int x, y, z;
	scanf("%d", &n);
	k = 1;
	ans = 0;
	while ((2 * k) <= n) {
		x = (n - 1) / k;
		x += k;
		if ((n - x) > ans) {
			ans = n - x;
			maxk = k;
		}
		k++;
	}
	x = 0;
	f(i, n)fin[i] = true;
	f(i, maxk) {
		y = (n - maxk + i) / maxk;
		x += y;
		fin[x] = false;
      x++;
	}
	s = 0;
	f(tt,10000) {
		s = 0;
		f(i, n)if (a[i])s++;
		if (s >= ans) {
			printf("0\n");
			fflush(stdout);
			return 0;
		}
		ch.clear();
		f(i, n) {
			if (fin[i] && (!a[i])) {
				a[i] = true;
				ch.push_back(i + 1);
			}
		}
		sz = ch.size();
		printf("%d", sz);
		f(i, sz)printf(" %d", ch[i]);
		printf("\n");
		fflush(stdout);
		scanf("%d", &s);
		s--;
		f(i, sz) {
			a[s] = false;
			s = (s + 1) % n;
		}
	}




	return 0;
}