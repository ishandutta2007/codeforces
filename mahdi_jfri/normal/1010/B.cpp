#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int iswrong[maxn];

int get(int x)
{
	cout << x << endl;
	int y;
	cin >> y;

	if(y == 0)
		exit(0);
	return y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m , n;
	cin >> m >> n;

	for(int i = 0; i < n; i++)
	{
		int x = get(1);

		if(x < 0)
			iswrong[i] = -1;
		else
			iswrong[i] = 1;
	}

	int l = 1 , r = m;

	int cnt = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;

		if(get(mid) * iswrong[cnt] > 0)
			l = mid + 1;
		else
			r = mid - 1;

		cnt++;
		cnt %= n;
	}
}