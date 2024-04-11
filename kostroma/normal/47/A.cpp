#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;

int main()
{
int n;
cin>>n;
int i=1;
while (i*(i+1)/2<=n)
{
	if (i*(i+1)==2*n)
	{
		printf ("YES");
		return 0;
	}
	i++;
}
printf ("NO");
return 0;
}