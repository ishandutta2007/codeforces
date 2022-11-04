#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , a[100001] , ans;

int main ()
{
	int i;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
	for (i = 2 ; i < n ; i++)
	    if (a[i] > a[1] && a[i] < a[n])
	        ans++;
	printf("%d\n",ans);        
    //system("PAUSE");
	return 0;
}