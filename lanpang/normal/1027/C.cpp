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

int T , n , a[maxn] , i , j , ax , ay , t;
vector <int> v;
double ans;

void jisuan(int x , int y)
{
	double aa = (((double)x*(double)x+(double)y*(double)y)/(double)x/(double)y+(double)1)*(double)4;
	if (aa < ans)
	{
		ans = aa;
		ax = x;
		ay = y;
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		v.clear();
		ans = 100000;
		ax = ay = 0;
		t = 0;
		for (i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (i = 1 ; i <= n ; i++)
		{
			j = i;
			while (j <= n && a[j] == a[i]) j++;
			if (j > i+1) v.push_back(a[i]);
			if (j > i+3)
			{
				t = 1;
				ans = 12;
				ax = ay = a[i];
				break;
			}
			i = j-1;
		}
		if (!t)
		{
			for (i = 0 ; i < v.size()-1 ; i++)
				jisuan(v[i],v[i+1]);
		}
		cout << ax << " " << ax << " " << ay << " " << ay << "\n";
	}
	return 0;
}