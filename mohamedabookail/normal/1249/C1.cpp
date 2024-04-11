/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = pow(3, i);
	}
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		while(true)
		{
			int cnt = n;
			for (int i = 9; i >= 0; i--)
			{
				if(arr[i] <= cnt)
					cnt -= arr[i];
			}
			if(!cnt)
			{
				cout << n << endl;
				break;
			}
			else
			{
				n++;
				cnt = n;
			}
		}
	}
}