#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll E = (ll)1e9 + 7;
const int N = 200100;

vector<int> g1[N], g2[N];
int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h;
	cin >> h;
	int n = 0;
	for (int i = 0; i <= h; i++)
	{
		cin >> a[i];
		n += a[i];
	}
	bool f = true;
	for (int i = 1; i < h; i++)
		if (a[i] >= 2 && a[i + 1] >= 2)
			f = false;
	if (f)
	{
		cout << "perfect";
		return 0;
	}
	vector<int> p1(n + 1), p2(n + 1);
	int t = 0;
	for (int i = 0; i < h; i++)
	{
		t += a[i];
		for (int j = 1; j <= a[i + 1]; j++)
			p1[t + j] = t - a[i] + 1;
	}
	t = 0;
	for (int i = 0; i < h; i++)
	{
		t += a[i];
		int k = 1;
		if (a[i] >= 2)
			k++;
		p2[t + 1] = t - a[i] + 1;
		for (int j = 2; j <= a[i + 1]; j++)
			p2[t + j] = t - a[i] + k;
	}
	cout << "ambiguous\n";
	for (int i = 1; i <= n; i++)
		cout << p1[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++)
		cout << p2[i] << ' ';
	return 0;
}