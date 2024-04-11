#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> X, Y;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		X.push_back(x); Y.push_back(y);
	}
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());
	if (X.size() != 2 || Y.size() != 2) printf("-1\n");
	else printf("%d\n", (X[1] - X[0]) * (Y[1] - Y[0]));
	return 0;
}