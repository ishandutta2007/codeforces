#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	int max = 0, cnt = 0, sum = 0, totalsum = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> A[i];
		if(i == 0)
		{
			sum += A[i];
		}
		totalsum += A[i];
		if(i != 0 && A[i] * 2 <= A[0])
		{
			cnt++;
			sum += A[i];
		}
	}
	if(sum < (totalsum + 2) / 2)
	{
		cout << 0;
		return 0;
	}
	cout << cnt + 1 << "\n";
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || A[i] * 2<= A[0])
		{
			cout << i + 1 << " ";
		}
	}
	return 0;
}