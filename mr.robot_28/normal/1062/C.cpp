#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
const int inf = 1e9 + 7;
int main()
{
	int n, q;
	cin >> n >> q;
	string h;
	cin >> h;
	vector <int> pref0(n), pref1(n);
	pref0[0] = 1 - h[0] + '0';
	vector <int> L(n + 1);
	L[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		L[i] = L[i - 1] * 2 % inf;
	}
	for(int i = 1; i < n; i++)
	{
		if(h[i] == '0')
		{
			pref0[i] = pref0[i - 1] +1;
		}
		else
		{
			pref0[i] = pref0[i - 1];
		}
	}
	for(int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		int p = L[b - a + 1], y;
		if(a == 1)
		{
			y = L[pref0[b - 1]];
		}
		else
		{
			y = L[pref0[b - 1] - pref0[a - 2]];
		}
		cout << (p - y + inf) % inf << endl;
	}
	return 0;
}