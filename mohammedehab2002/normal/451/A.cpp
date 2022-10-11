#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,ans;
	cin >> n >> m;
	ans=min(n,m);
	if (ans%2)
	cout << "Akshat";
	else
	cout << "Malvika";
}