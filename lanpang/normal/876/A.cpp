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

int n , a , b , c; 

int main ()
{
	cin >> n >> a >> b >> c;
	if (n == 1) cout << "0\n";
	else if (n == 2) cout << min(a,b) << "\n";
		 else if (c < min(a,b)) cout << c*(n-2)+min(a,b) << "\n";
			  else cout << (n-1)*min(a,b) << "\n";
	//system("PAUSE");
	return 0;
}