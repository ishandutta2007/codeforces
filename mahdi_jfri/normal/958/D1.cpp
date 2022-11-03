#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 2e5 + 20;

ld a[maxn] , b[maxn];

map<ld , int> mp;

int main()
{
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	*/

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x , y , z;
		char ch;
		cin >> ch >> x >> ch >> y >> ch >> ch >> z;

		a[i] = x + y;
		b[i] = z;

		mp[a[i] / b[i]]++;
	}
	
	for(int i = 0; i < n; i++)
		cout << mp[a[i] / b[i]] << " ";
	cout << endl;
}