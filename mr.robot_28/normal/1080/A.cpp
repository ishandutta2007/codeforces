#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int a = (2 * n + k - 1) / k;
	int b = (5 * n + k - 1) / k;
	int c = (8 * n + k - 1) / k;
	cout << a + b + c;
    return 0;
}