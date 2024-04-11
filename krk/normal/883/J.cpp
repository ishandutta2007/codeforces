#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn];
int b[Maxn];
int p[Maxn];
vector <ii> seq;
int pnt;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		seq.push_back(ii(b[i], i));
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &p[i]);
	sort(seq.begin(), seq.end());
	priority_queue <ii> Q;
	int mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		mx = max(mx, a[i]);
		while (pnt < seq.size() && seq[pnt].first <= mx) {
			int ind = seq[pnt].second;
			Q.push(ii(-p[ind], ind));
			pnt++;
		}
		while (!Q.empty() && a[i] >= -Q.top().first) {
			res++; 
			a[i] += Q.top().first; Q.pop();
		}
		if (!Q.empty()) {
			ii v = Q.top(); Q.pop();
			v.first += a[i];
			Q.push(v);
		}
	}
	printf("%d\n", res);
	return 0;
}