#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,p,k,i;
	cin >> n >> p >> k;
	if (p-k>1)
	cout << "<< ";
	for (i=max(p-k,1);i<p;i++)
	cout << i << " ";
	cout << "(" << p << ") ";
	for (i=p+1;i<=min(p+k,n);i++)
	cout << i << " ";
	if (p+k<n)
	cout << ">>";
}