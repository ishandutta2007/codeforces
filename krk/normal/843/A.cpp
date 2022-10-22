#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
bool tk[Maxn];
vector <vector <int> > res;

int main()
{
	scanf("%d", &n);
	vector <int> un;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		un.push_back(a[i]);
	}
	sort(un.begin(), un.end());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
	for (int i = 0; i < n; i++) if (!tk[i]) {
		vector <int> seq;
		int cur = i;
		while (!tk[cur]) {
			seq.push_back(cur); tk[cur] = true;
			cur = a[cur];
		}
		res.push_back(seq);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d", res[i].size());
		for (int j = 0; j < res[i].size(); j++)
			printf(" %d", res[i][j] + 1);
		printf("\n");
	}
	return 0;
}