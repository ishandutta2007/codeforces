#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<map>
#define N 505
using namespace std;
int n;
inline int ReadInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
map<int, int, greater<int> >mp;
int gcd(int a, int b)
{
    if(a < b) swap(a, b);
	while(b)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}
int ans[N];

int main()
{
    n = ReadInt();
    int nn = n * n;
    for(int i = 0; i < nn; i ++)
	{
        int x;
        x = ReadInt();
        mp[x] ++;
    }
    int len = 0;
    for(map<int, int, greater<int> >::iterator it = mp.begin(); it != mp.end(); ) 
    {
    	if(it -> second == 0)
    	{
    		it ++;
    		continue;
		}
		-- it -> second;
		for(int i = 0; i < len; i ++)
		{
			int gcdn = gcd(it -> first, ans[i]);
			mp[gcdn] -= 2;
		}
		ans[len ++] = it -> first;
	}
    
    for(int i = 0; i < n; i ++)
        printf("%d ", ans[i]);
    return 0;
}