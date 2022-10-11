#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i;
	string l="abcd";
	cin >> n;
	for (i=0;i<n/4;i++)
	cout << l;
	for (i=(n/4)*4;i<n;i++)
	cout << l[i-(n/4)*4];
}