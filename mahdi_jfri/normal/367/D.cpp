#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;
const int maxm = 21;

bool dp[1 << maxm];

int t[maxm] , a[maxn];

int main()
{
	int n , m , d;
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			a[--x] = i;
		}
	}
	for(int i = 0; i < n; i++)
	{
		t[a[i]]++;
		if(i - d >= 0)
			t[a[i - d]]--;
		if(i + 1 < d)
			continue;
		int x = 0;
		for(int j = 0; j < m; j++)
			if(t[j])
				x |= (1 << j);
		x = (1 << m) - 1 - x;
		dp[x] = 1;
	}
	for(int i = (1 << m) - 1; i >= 0; i--)
		for(int j = 0; j < m; j++)
			if(bit(i , j))
				dp[i ^ (1 << j)] |= dp[i];
	int res = m;
	for(int i = 0; i < (1 << m); i++)
		if(!dp[i])
			res = min(res , __builtin_popcount(i));
	printf("%d\n" , res);
}