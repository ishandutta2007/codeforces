#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

struct Ad {
	int val, tims, ind;
	bool operator <(const Ad &b) const {
		if (val != b.val) return val < b.val;
		if (tims != b.tims) return tims > b.tims;
		return ind > b.ind;
	}
};

int n, m;
map <int, vector <int> > M;
priority_queue <Ad> Q;
int nums[Maxn];
int res[Maxn];
int tot1, tot2;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int p; scanf("%d", &p);
		M[p].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		Ad A; A.val = x; A.tims = 0; A.ind = i;
		Q.push(A);
	}
	while (!Q.empty()) {
		Ad A = Q.top(); Q.pop();
		map <int, vector <int> >::iterator it = M.find(A.val);
		if (it != M.end() && !it->second.empty()) {
			int ind = it->second.back();
			tot1++; tot2 += A.tims;
			nums[A.ind] = A.tims;
			res[ind] = A.ind + 1;
			it->second.pop_back();
		} else if (A.val != 1) {
			A.val = (A.val + 1) / 2; A.tims++;
			Q.push(A);
		}
	}
	printf("%d %d\n", tot1, tot2);
	for (int i = 0; i < m; i++)
		printf("%d%c", nums[i], i + 1 < m? ' ': '\n');
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}