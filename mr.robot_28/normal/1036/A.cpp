#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<stack>
using namespace std;
int main()
{
	long long n, k;
	cin >> n >> k;
	cout << k / n + (k % n !=0);
	return 0;
}