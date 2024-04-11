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
#include <iomanip>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
int L[Maxn], R[Maxn];
vector <ii> st;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &L[i], &R[i]);
	for (int i = 1; i <= n; i++) if (L[i] == 0) {
		int cur = i;
		while (R[cur] != 0) cur = R[cur];
		st.push_back(ii(i, cur));
	}
	for (int i = 0; i + 1 < st.size(); i++) {
		R[st[i].second] = st[i + 1].first;
		L[st[i + 1].first] = st[i].second;
	}
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", L[i], R[i]);
	return 0;
}