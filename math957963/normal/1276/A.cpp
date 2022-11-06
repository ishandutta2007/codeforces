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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200010


int main() {
	char a[N];
	f(i, N)a[i] = 0;
	vector<int>b;
	vector<int>c;
	int n, t, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);

	f(tt, t) {
		scanf("%s", a);
		n = strlen(a);
		b.clear();
		f(i, n-2) {
			if (a[i] == 'o'&&a[i + 1] == 'n'&&a[i + 2] == 'e')b.push_back(i);
			if (a[i] == 't'&&a[i + 1] == 'w'&&a[i + 2] == 'o')b.push_back(i);
		}
		c.clear();
		k = 0;
		while (k < b.size()) {
			if ((k + 1) < b.size()) {
				if (b[k + 1] <= b[k] + 2) {
					c.push_back(b[k] + 3);
					k += 2;
}
				else {
					c.push_back(b[k] + 2);
					k ++;
				}
			}
			else {
				c.push_back(b[k] + 2);
				k++;
			}
		}
		printf("%d\n", c.size());
		f(i, c.size()) {
			printf("%d", c[i]);
			if (i < (c.size() - 1))printf(" ");
		}
      			printf("\n");
		f(i, n + 1)a[i] = 0;
	}



	return 0;
}