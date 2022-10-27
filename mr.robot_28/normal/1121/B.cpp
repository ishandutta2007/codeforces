#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	vector <int> W(2e5 + 1);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		W[A[i]] ++;
	}
	int max = 0;
	for(int midd = 1; midd <= 2e5; midd++)
	{
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			if(midd >= A[i] && W[midd - A[i]] == 1)
			{
				count++;
			}
		}
		if(count > max * 2)
		{
			max = count / 2;
		}
	}
	cout << max;
	return 0;
}