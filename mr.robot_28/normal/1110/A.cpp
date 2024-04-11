#include<bits/stdc++.h> 
using namespace std;
int main () {
	int b, k;
	cin >> b >> k;
	vector <int> A(k);
	for(int i = 0; i <k; i++)
	{
		cin >> A[i];
	}
	if(b % 2 == 0)
	{
		if(A[k - 1] % 2 == 0)
		{
			cout << "even";
		}
		else
		{
			cout << "odd";
		}
	}
	else
	{
		int count = 0;
		for(int i = 0; i < k; i++)
		{
			if(A[i] % 2 == 1)
			{
				count++;
			}
		}
		if(count % 2 == 0)
		{
			cout << "even";
		}
		else
		{
			cout << "odd";
		}
	}
	return 0;
}