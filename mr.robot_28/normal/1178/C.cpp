#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int CONST = 998244353;
int main()
{
	#define int long long
	int n, m;
	cin >> n >> m;
	int ans = 1;
	for(int i = 0; i < n + m; i++)
	{
		ans = (ans * 2) % CONST;
	}
	cout << ans;
	return 0;
}