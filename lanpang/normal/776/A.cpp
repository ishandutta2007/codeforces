#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char a[11] , b[11] , c[11] , d[11] , l;
int n , i , j;

void swap1(int k)
{
	l = strlen(d); 
	if (k == 1)
	{
		for (j = 0 ; j <= l ; j++)
		    a[j] = d[j];
	}
	else
	{
		for (j = 0 ; j <= l ; j++)
		    b[j] = d[j];
	}
}

int main ()
{
	cin >> a >> b >> n;
	cout << a << " " << b << "\n";
    for (i = 1 ; i <= n ; i++)
    {
    	cin >> c >> d;
    	if (!strcmp(a,c))
    	    swap1(1);
    	else
		    swap1(2);
	    cout << a << " " << b << "\n";
    }
    //system("PAUSE");
	return 0;
}