#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int max = A[0], min = A[0], cnt = 1, maxcnt = 1;
	for(int i = 1; i < n; i++)
	{
		if(abs(A[i] - min) <= 1 && abs(A[i] - max) <= 1)
		{
			cnt++;
			if(A[i] < min)
			{
				min = A[i];
			}
			if(A[i] > max)
			{
				max = A[i];
			}
		}
		else
		{
			min = max = A[i];
			if(maxcnt < cnt)
			{
				maxcnt = cnt;
			}
			cnt = 1;
			for(int j = i - 1; j >= 0; j--)
			{
				if(abs(A[j] - min) <= 1 && abs(A[j] - max) <= 1)
				{
					cnt++;
					if(A[j] < min)
					{
						min = A[j];
					}
					if(A[j] > max)
					{
						max = A[j];
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	if(maxcnt < cnt)
	{
		maxcnt = cnt;
	}
	cout << maxcnt;
    return 0;
}