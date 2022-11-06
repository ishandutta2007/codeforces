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
#define N 300100


int main() {
	vector<pair<pair<int, int>, int> >a;
	vector<pair<pair<int, int>, int> >b;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d", &x, &y);
		if (x < y)a.push_back(make_pair(make_pair(x, y),i+1));
		else b.push_back(make_pair(make_pair(x, y), i + 1));
	}
	if (a.size() > b.size()) {
		printf("%d\n", a.size());
		sort(a.begin(), a.end());
		f(i, a.size()) {
			printf("%d", a[a.size() - i - 1].second);
			if (i < a.size() - 1)printf(" ");
			else printf("\n");
		}
}
	else {
		printf("%d\n", b.size());
		sort(b.begin(), b.end());
		f(i, b.size()) {
			printf("%d", b[i].second);
			if (i < b.size() - 1)printf(" ");
			else printf("\n");
		}
	}



	return 0;
}