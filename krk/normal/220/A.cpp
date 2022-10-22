#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn], mx[Maxn];

bool Sorted()
{
	for (int i = 1; i < n; i++)
		if (a[i - 1] > a[i]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mx[0] = 0;
	for (int i = 1; i < n; i++)
		if (a[i] > a[mx[i - 1]]) mx[i] = i;
		else mx[i] = mx[i - 1];
	int mn = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[mx[i]] > a[mn]) { swap(a[mx[i]], a[mn]); break; }
		if (i == 0) break;
		if (a[i - 1] < a[mn]) mn = i - 1;
	}
	printf("%s\n", Sorted()? "YES": "NO");
	return 0;
}