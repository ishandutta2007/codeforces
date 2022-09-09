#include <stdio.h>
#include <set>
#include <vector>
#include <math.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
void prepare ()
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
#else 
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
}


int main( )
{
	int n;
	cin>>n;
	if (n==2)
	{
		printf ("2");
		return 0;
	}
	int i=2, k=2;
	int j;
	for (j=1; j<n; j++)
	{
		i%=n;
		if (i==0)
			i=n;
		printf ("%d ", i);
		i+=k;
		k++;
	}
	return 0;
}