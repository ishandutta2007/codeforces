#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int res[maxn];
int main()
{
	int n;
	cin >> n;
	int a , b , c;
	cout << "? 1 2" << endl;
	cin >> a;
	cout << "? 1 3" << endl;
	cin >> b;
	cout << "? 2 3" << endl;
	cin >> c;
	res[0] = (a + b - c) / 2;
	res[1] = a - res[0];
	res[2] = b - res[0];
	for(int i = 3; i < n; i++)
	{
		cout << "? 1 " << i + 1 << endl;
		int x;
		cin >> x;
		res[i] = x - res[0];
	}
	cout << "! ";
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}