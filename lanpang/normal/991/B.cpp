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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , i , s , x , sn , cnt;
priority_queue <int> q;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> x;
		s += x;
		q.push(-x);
	}
	sn = n*4+(n+1)/2;
	if (s >= sn) cout << "0\n";
	else
	{
		for (i = 1 ; i <= n ; i++)
		{
			x = q.top();
			q.pop();
			s += 5+x;
			cnt++;
			if (s >= sn)
			{
				cout << i << "\n";
				break;
			}
		}
	} 
	return 0;
}