#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	int k,n,w,i;
	cin >> k >> n >> w;
	for (i=1;i<=w;i++)
	n-=i*k;
	if (n>0)
	cout << 0;
	else
	cout << n*-1;
}