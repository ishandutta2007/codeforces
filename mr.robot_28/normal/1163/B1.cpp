#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int max = 1, min = 1, imax = 0;
	vector <int> L(1e5 + 1), CNT(1e5 + 1);
	for(int i = 0; i < n; i++)
	{
		L[A[i]]++;
		if(max + 1 == L[A[i]])
		{
		//	cout << max;
			max = L[A[i]];
		}
		if(L[A[i]] == 1)
		{
			min = L[A[i]];
		}
		CNT[L[A[i]]]++;
		if(L[A[i]] - 1 > 0)
		{
			CNT[L[A[i]] - 1]--;
		}
		if(CNT[min] == 0)
		{
			min++;
		}
		if(min + 1 >= max && CNT[max] == 1 || min == 1 && (CNT[min] == 1 && i + 1 == min + max * CNT[max] || max == 1))
		{ 
			imax = i + 1;	
		}
	}
	cout << imax;
    return 0;
}