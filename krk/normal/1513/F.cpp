#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int b[Maxn];
vector <ii> A, B;
ll sum;
int mx;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		sum += abs(a[i] - b[i]);
	}
	for (int i = 0; i < n; i++)
		if (a[i] < b[i]) A.push_back(ii(a[i], b[i]));
		else if (a[i] > b[i]) B.push_back(ii(b[i], a[i]));
	int amx = 0, bmx = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = 0, j = 0;
	while (i < A.size() || j < B.size())
		if (i < A.size() && (j >= B.size() || A[i].first <= B[j].first)) {
			if (A[i].first <= bmx) mx = max(mx, min(bmx, A[i].second) - A[i].first);
			amx = max(amx, A[i].second);
			i++;
		} else {
			if (B[j].first <= amx) mx = max(mx, min(amx, B[j].second) - B[j].first);
			bmx = max(bmx, B[j].second);
			j++;
		}
	sum -= 2ll * ll(mx);
	printf("%I64d\n", sum);
    return 0;
}