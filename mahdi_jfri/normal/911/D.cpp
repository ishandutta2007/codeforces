#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn] , inv;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				inv++;

	int q;
	cin >> q;
	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l--;
		if(((r - l) / 2) % 2)
			inv++;
		if(inv % 2)
			cout << "odd" << endl;
		else
			cout << "even" << endl;
	}
}