#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int t;
	string a;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> a;
		int count = 0, count1 = 0, count2 =0;
		for(int j = 0; j < a.size(); j++)
		{
			if(a[j] >= '0' && a[j] <= '9')
			{
				count++;
			}
			else if(a[j] >= 'a' && a[j] <= 'z')
			{
				count1++;
			}
			else
			{
				count2++;
			}
		}
		if(count > 0 && count1 > 0 && count2 > 0)
		{
			cout << a << endl;
		}
		else
		{
			for(int j = 0; j < a.size(); j++)
			{
				if(count == 0 && count1 > 1 && a[j] >= 'a' && a[j] <= 'z')
				{
					count++;
					count1--;
					a[j] = '0';
				}
				else if(count == 0 && count2 > 1 && a[j] >= 'A' && a[j] <= 'Z')
				{
					count++;
					count2--;
					a[j] = '0';
				}
				else if(count1 == 0 && count > 1 && a[j] >= '0' && a[j] <= '9')
				{
					count1++;
					count--;
					a[j] = 'a';
				}
				else if(count1 == 0 && count2 > 1 && a[j] >= 'A' && a[j] <= 'Z')
				{
					count1++;
					count2--;
					a[j] = 'a';
				}
				else if(count2 == 0 && count > 1 && a[j] >= '0' && a[j] <= '9')
				{
					count2++;
					count--;
					a[j] = 'A';
				}
				else if(count2 == 0 && count1 > 1 && a[j] >= 'a' && a[j] <= 'z')
				{
					count2++;
					count1--;
					a[j] = 'A';
				}
			}
			cout << a << endl;
		}
	}
	return 0;	
}