#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
vector <int> A;
int binsearch(int l, int r,int a)
{
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(A[midd] <= a)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	return r - 1;
}
int main()
{
	int n;
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		int count = binsearch(i, n, A[i] + 5) - i + 1;
		//cout << count;
		if(count > max)
		{
			max = count;
		}
	}
	cout << max;
    return 0;
}