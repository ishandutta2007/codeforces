#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	string a;
	int n, k;
	cin >> n >> k;
	cin >> a;
	vector <int> A(k, 0);
	for(int i = 0; i < a.size(); i++)
	{
		A[a[i] - 'A']++;
	}
	int min = a.size();
	for(int i = 0; i < k; i++)
	{
		if(min > A[i])
		{
			min = A[i];
		}
	}
	cout << min * k;
}