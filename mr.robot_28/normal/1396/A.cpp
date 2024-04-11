#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(n == 1)
	{
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << -a[0];
		return 0;
	}
	cout << "1 1\n";
	cout << -a[0] << "\n";
	a[0] = 0;
	cout << "2 " << n << "\n";
	for(int i = 1; i < n; i++)
	{
		int add = (a[i] % n) * (n - 1);
		cout << add << " ";
		a[i] += add;
	}
	cout << "\n";
	cout << 1 << " " << n << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << -a[i] << " ";
	}
	return 0;
}