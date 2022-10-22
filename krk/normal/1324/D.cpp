#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int b[Maxn];
vector <int> un;
long long res;
int BIT[Maxn];

void Insert(int ind)
{
	for (int i = ind + 1; i <= un.size(); i += i & -i)
		BIT[i]++;
}

int Get(int ind)
{
	int res = 0;
	for (int i = ind + 1; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		un.push_back(b[i] - a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 1; i <= n; i++) {
		int ind = lower_bound(un.begin(), un.end(), a[i] - b[i]) - un.begin();
		res += Get(ind - 1);
		ind = lower_bound(un.begin(), un.end(), b[i] - a[i]) - un.begin();
		Insert(ind);
	}
	cout << res << endl;
    return 0;
}