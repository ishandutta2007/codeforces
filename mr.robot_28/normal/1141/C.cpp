#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> Q(n - 1);
    for(int i = 0; i < n - 1; i++)
    {
    	cin >> Q[i];
	}
	int sum = 0;
	int max1 = 0, imax = 0;
	for(int i = 0; i < n - 1; i++)
	{
		sum += Q[i];
		if(max1 < sum)
		{
			max1 = sum;
			imax = i + 1;
		}
	}
	vector <int> A(n, 0);
	A[imax] = n;
	sum = 0;
	for(int j = imax - 1; j >= 0; j--)
	{
		sum -= Q[j];
		A[j] = sum + n;
	}
	sum = 0;
	for(int j = imax; j < n - 1; j++)
	{
		sum += Q[j];
		A[j + 1] = sum + n;
	}
	map<int, int> W;
	for(int i = 0; i < n; i++)
	{
		if(W[A[i]] != 0 || A[i] < 1 || A[i] > n)
		{
			cout << -1;
			return 0;
		}
		W[A[i]] ++ ;
	}
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " " ;
	}
    return 0;
}