#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxm = 3005;

int n, v;
int a[Maxm], b[Maxm];
vector <int> lst[Maxm], fir[Maxm];
int res;

int main()
{
	scanf("%d %d", &n, &v);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		fir[a[i]].push_back(i); lst[a[i] + 1].push_back(i);
	}
	for (int i = 0; i < Maxm; i++) {
		int lft = v;
		for (int j = 0; j < lst[i].size(); j++) {
			int ind = lst[i][j];
			int tk = min(lft, b[ind]); lft -= tk; b[ind] -= tk; res += tk;
		}
		for (int j = 0; j < fir[i].size(); j++) {
			int ind = fir[i][j];
			int tk = min(lft, b[ind]); lft -= tk; b[ind] -= tk; res += tk;
		}
	}
	printf("%d\n", res);
	return 0;
}