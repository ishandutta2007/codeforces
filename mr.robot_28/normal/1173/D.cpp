#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define int long long
const int eps = 998244353;
main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n - 1; i ++)
	{
		int x, y;
		cin >> x >> y;
		A[x - 1]++;
		A[y - 1]++;
	}
	int cnt = n;
	for(int i = 0; i < n; i++)
	{
		while(A[i] > 1)
		{
			cnt = (cnt * A[i]) % eps;
			A[i]--;
		 } 
	}
	cout << cnt;
	return 0;
}