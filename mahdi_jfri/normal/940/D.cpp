#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	string b;
	cin >> b;

	int l = -1e9 , r = 1e9;

	for(int i = 4; i < n; i++)
	{
		vector<int> x;
		for(int j = i; j > i - 5; j--)
			x.pb(a[j]);
		sort(x.begin() , x.end());

		if(b[i] == '1' && b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0')
			l = max(l , x.back() + 1);
		if(b[i] == '0' && b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1')
			r = min(r , x[0] - 1);
	}

	cout << l << " " << r << endl;
}