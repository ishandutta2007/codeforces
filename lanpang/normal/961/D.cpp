#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y;
	bool operator < (const mmp op) const{
		if (x == op.x) return y < op.y;
		else return x < op.x;
	}
}a[maxn] , b , m;
int n , f[maxn];
map <mmp,int> mp;
vector <int> v;

int gcd(int x , int y)
{
	if (y == 0) return x;
	else return gcd(y,x%y);
}

int jisuan()
{
	int i , g;
	if (v.size() <= 2) return 1;
	for (i = 1 ; i < v.size() ; i++)
	{
		b.x = a[v[i]].x-a[v[0]].x;
		b.y = a[v[i]].y-a[v[0]].y;
		if (b.x < 0)
		{
			b.x = -b.x;
			b.y = -b.y;
		}
		if (b.x == 0 || b.y == 0)
		{
			if (b.x == 0) b.y = 1;
			else b.x = 1;
		}
		else
		{
			g = gcd(abs(b.x),abs(b.y));
			b.x /= g;
			b.y /= g;
		}
		if (i == 1)
		{
			m.x = b.x;
			m.y = b.y;
		}
		else
		{
			if (m.x != b.x || m.y != b.y) return 0;
		}
	}
	return 1;
}

int check(int x)
{
	mp.clear();
	int i , j=0 , g;
	for (i = 1 ; i <= n ; i++)
	{
		if (i != x)
		{
			b.x = a[i].x-a[x].x;
			b.y = a[i].y-a[x].y;
			if (b.x < 0)
			{
				b.x = -b.x;
				b.y = -b.y;
			}
			if (b.x == 0 || b.y == 0)
			{
				if (b.x == 0) b.y = 1;
				else b.x = 1;
			}
			else
			{
				g = gcd(abs(b.x),abs(b.y));
				b.x /= g;
				b.y /= g;
			}
			mp[b]++;
			if (mp[b] > j)
			{
				j = mp[b];
				m.x = b.x;
				m.y = b.y;
			}
		}
	}
	if (j+1 >= (n+1)/2)
	{
		v.clear();
		for (i = 1 ; i <= n ; i++)
		{
			if (i != x)
			{
				b.x = a[i].x-a[x].x;
				b.y = a[i].y-a[x].y;
				if (b.x < 0)
				{
					b.x = -b.x;
					b.y = -b.y;
				}
				if (b.x == 0 || b.y == 0)
				{
					if (b.x == 0) b.y = 1;
					else b.x = 1;
				}
				else
				{
					g = gcd(abs(b.x),abs(b.y));
					b.x /= g;
					b.y /= g;
				}
				if (b.x != m.x || b.y != m.y) v.push_back(i);
			}
		}
		return jisuan();
	}
	else return 0;
}

int main()
{
	int i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	if (n <= 4) k = 1;
	else
	{
		srand(time(NULL));
		k = 0;
		for (i = 1 ; i <= 30 ; i++)
		{
			j = (rand()*(rand()%30+1))%n+1;
			if (check(j))
			{
				k = 1;
				break;
			}
		}
	}
	if (k) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}