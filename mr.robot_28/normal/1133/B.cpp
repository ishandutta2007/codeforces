#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> K(k);
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		K[A[i] % k] ++;
	}
	for(int i = 0; i <= k / 2; i++)
	{
		if(i == 0)
		{
			count += K[i] - K[i] % 2;
		}
		else if(i * 2 == k)
		{
			count += K[i] - K[i] % 2;
		}
		else
		{
			count += 2 * min(K[i], K[k- i]);
		}
	}
	cout << count;
    return 0;
}