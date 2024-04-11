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

typedef long double ld;
typedef pair <ld, int> ldi;

const int lim = 1000000;

int n, s;
vector <ldi> V;

int main()
{
	scanf("%d %d", &n, &s);
	while (n--) {
		int x, y, p; scanf("%d %d %d", &x, &y, &p);
		V.push_back(ldi(sqrt(ld(x) * x + ld(y) * y), p));
	}
	sort(V.begin(), V.end());
	int i = 0;
	while (i < V.size() && s < lim) s += V[i++].second;
	if (s < lim) printf("-1\n");
	else printf("%.10lf\n", double(V[i - 1].first));
	return 0;
}