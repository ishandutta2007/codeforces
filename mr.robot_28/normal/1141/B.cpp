#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> A(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i];
	}
	bool flag = true;
	int max1 = 0;
	int st = 0, end = 0, r = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i])
		{
			r ++;
			if(flag)
			{
				st ++;
			}
		}
		else
		{
			if(r > max1)
			{
				max1 = r;
			}
			r = 0;
			flag = false;
		}
	}
	flag = true;
	for(int i = n - 1; i >= 0; i--)
	{
		if(A[i])
		{
			end ++;
		}
		else
		{
			break;
		}
	}
	cout << max(max1, end + st);
    return 0;
}