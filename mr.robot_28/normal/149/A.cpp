#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int k, count = 0;
	cin >> k;
	vector <int> A(12);
	for(int i = 0; i < 12; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for(int i = 11; i >= 0; i--)
	{
		if(k <= 0)
		{
			break;
		}
		k -= A[i];
		count++;
	}
	if(k > 0)
	{
		cout << -1;
		return 0;
	}
	cout << count;
    return 0;
}