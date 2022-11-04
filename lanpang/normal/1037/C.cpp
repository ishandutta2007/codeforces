#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , i , s;
char a[maxn] , b[maxn]; 
vector<int> v;

int main()
{
	cin >> n;
	cin >> a;
	cin >> b;
	for (i = 0 ; i < n ; i++)
	{
		if (a[i] != b[i]) v.push_back(i);
	}
	s = v.size(); 
	for (i = 1 ; i < v.size() ; i++)
	{
		if (v[i] == v[i-1]+1 && a[v[i]] != a[v[i-1]]) 
		{
			s--;
			i++;
		}
	}
	cout << s << "\n";
	return 0;
}