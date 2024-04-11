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

char a[10][10] = {"Danil","Olya","Slav","Ann","Nikita"} , c[1000];
int b[10] , l , s;

int main ()
{
	int i , j , k , t;
	cin >> c;
	l = strlen(c);
	for (i = 0 ; i < 5 ; i++)
	{
		b[i] = strlen(a[i]);
	}
	for (i = 0 ; i < 5 ; i++)
	{
		for (j = 0 ; j < l-b[i]+1 ; j++)
		{
			t = 0;
			for (k = 0 ; k < b[i] ; k++)
			{
				if (a[i][k] != c[j+k])
				{
					t = 1;
					break;
				}
			}
			if (!t) s++;
		}
	}
	if (s == 1) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}