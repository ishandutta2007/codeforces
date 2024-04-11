#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
using namespace std;
int main()
{
	#define int long long
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> A(m);
	for(int i =0; i < m; i++)
	{
		cin >> A[i];
	}
	int cnt = 0, ans = 0;
	int i = 0;
	while(i < m)
	{
		int j = i + 1;
		while(j < m  && (A[j] - cnt - 1) / k == (A[i] - cnt - 1) / k)
		{
			j++;
		}
		j--;
		cnt += j - i + 1;
		i = j;
		i++;
		ans++;
	}
	cout << ans;
	return 0;
}