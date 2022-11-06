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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	int a[N];
	int aa[N];
	f(i, N)a[i] = 0;
	int n, k, sz;
	int x, y, z;
	vector<int>sa;
	vector<int>sb;
	vector<pair<int,int> >b;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &a[i]);
		aa[i] = a[i];
	}

	for(int i=n-1;i>=0;i--){
		b.clear();
		f(j, i) {
			if (aa[j] > aa[i])b.push_back(make_pair(aa[j], j));
		}
		sort(b.begin(), b.end());
		sz = b.size();
		f(j, sz) {
			sa.push_back((b[j].second) + 1);
			sb.push_back(i + 1);
			swap(a[b[j].second], a[i]);
		}
	}
	sz = sa.size();
	printf("%d\n", sz);
	f(i, sz)printf("%d %d\n", sa[i], sb[i]);


	return 0;
}