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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a;

int ss(int x)
{
	int j , c=1;
	for (j = 2 ; j <= sqrt(x) && c ; j++)
		if (!(x%j)) c = 0;
	return c;
}

int main ()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a);
		if (a < 4 || (a < 12 && ss(a))) printf("-1\n");
		else 
			if (a%4%2==0) printf("%d\n",a/4);
			else printf("%d\n",a/4-1);
	}
	//system("PAUSE");
	return 0;
}