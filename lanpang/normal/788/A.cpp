#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , a[100001] , f[100001][2] , s[100001][2] , mi[2] , ma[2]; 

int main ()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	for (i = 1 ; i < n ; i++)
	{
		f[i][i%2] = fabs(a[i]-a[i+1]);
		f[i][(i%2+1)%2] = -fabs(a[i]-a[i+1]);
	}
	s[0][0] = 0;
	s[0][1] = 0;
	mi[0] = 0;
	mi[1] = 0;
	ma[0] = 0;
	ma[1] = 0;
	for (i = 1 ; i < n ; i++)
	{
		s[i][0] = f[i][0]+s[i-1][0];
		s[i][1] = f[i][1]+s[i-1][1];
		if (mi[0] > s[i][0])
		    mi[0] = s[i][0];
		if (mi[1] > s[i][1])
		    mi[1] = s[i][1];
		if (ma[0] < s[i][0]-mi[0])
		    ma[0] = s[i][0]-mi[0];
		if (ma[1] < s[i][1]-mi[1])
		    ma[1] = s[i][1]-mi[1];
	}
	cout << max(ma[0],ma[1]) << "\n";
	//system("PAUSE");
	return 0;
}