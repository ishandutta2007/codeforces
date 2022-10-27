#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		if(k % 3 == 0)
		{
			int np = n % (k + 1);
			if(np % 3 == 0 && np != k)
			{
				cout << "Bob" << "\n";
			}
			else
			{
				cout << "Alice\n";
			}
		}
		else
		{
			int np = n % 3;
			if(np == 0)
			{
				cout << "Bob\n";
			}
			else
			{
				cout << "Alice\n";
			}
		}
	}
	return 0;
}