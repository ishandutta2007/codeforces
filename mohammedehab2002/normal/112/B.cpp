#include <iostream>
using namespace std;
int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	if  ((x==n/2 || x==n/2+1) && (y==n/2 || y==n/2+1))
	cout << "NO";
	else
	cout << "YES";
}