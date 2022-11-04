#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e2+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

char a[10] , n , b[maxn][10];

int main ()
{
	int i , j;
	scanf("%s%d",&a,&n);
	for (i = 1 ; i <= n ; i++)
		scanf("%s",b[i]);
	int c = 0;
	for (i = 1 ; i <= n ; i++)
	{
		if (b[i][0] == a[0] && b[i][1] == a[1]) c = 1;
		for (j = 1 ; j <= n ; j++)
			if (b[i][1] == a[0] && b[j][0] == a[1]) c = 1; 
	}
	if (c) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}