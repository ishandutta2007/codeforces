#include<bits/stdc++.h> 
using namespace std;
int main () {
	int n;
	cin >> n;
	int count1 = 0, count2 = 0;
	vector <int>A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(A[i] > 0)
		{
			count1++;
		}
		else if(A[i] < 0)
		{
			count2++;
		}
	}
	if(count1 >= (n + 1) / 2)
	{
		cout << 1;
	}
	else if(count2 >= (n + 1) / 2)
	{
		cout << -1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}