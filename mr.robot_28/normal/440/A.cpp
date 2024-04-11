#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, a = 1;
	cin >> n;
	int A[n - 1];
	for(int i = 0; i < n - 1; i++)
	{
		cin >> A[i];
	}
	sort(A, A + n - 1);
	for(int i = 0; i < n - 1; i++)
	{
		if(A[i] == a)
		{
			a++;
		}
	}
	cout << a;
    return 0;
}