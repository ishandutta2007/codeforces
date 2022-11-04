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

LL n , m , s1 , l;
vector <LL> a[maxn] , b[maxn]; 

LL check1(LL x)
{
	if (x == 1) return 1;
	if (x == 2) return 0;
	if (x == 3) return 0;
	LL y=sqrt(x) , i;
	for (i = 2 ; i <= y ; i++)
	{
		if (x%i==0) return 1;
	}
	return 0;
}

int main ()
{
	LL i , j , k; 
	cin >> n >> m;
	s1 = n-1;
	while (check1(s1)) s1++;
	for (i = n ; i >= 2 ; i--)
	{
		a[i].push_back(i-1);
		if (i == n) b[i].push_back(s1-n+2);
		else b[i].push_back(1);
	}
	l = n-1;
	for (i = 2 ; l < m && i <= n-1 ; i++)
	{
		for (j = n ; l < m && j >= i+1 ; j--)
		{
			k = j-i;
			a[j].push_back(k);
			b[j].push_back(s1);
			l++;
		}
	}
	cout << s1 << " " << s1 << "\n";
	for (i = n ; i >= 2 ; i--)
	{
		for (j = 0 ; j < a[i].size() ; j++)
		{
			k = a[i][j];
			printf("%I64d %I64d %I64d\n",k,i,b[i][j]);
		}
	}
	//system("PAUSE");
	return 0;
}