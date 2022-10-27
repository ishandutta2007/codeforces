#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int max = 0;
	int count = 0;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(i == max)
		{
			count++;
		}
		if(A[i] > max)
		{
			max = A[i];
		}
	}
	cout << count;
	return 0;
}