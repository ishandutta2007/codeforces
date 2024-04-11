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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

char a[100];
int i , n , s , p;

int main ()
{
	cin >> a;
	n = strlen(a);
	for (i = 0 ; i < n ; i++)
	{
		if ('a' <= a[i] && a[i] <= 'z') 
		{
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') s++;
		}
		else
		{
			p = a[i]-'0';
			if (p % 2) s++;
		}
	}
	cout << s << "\n";
	//system("PAUSE");
	return 0;
}