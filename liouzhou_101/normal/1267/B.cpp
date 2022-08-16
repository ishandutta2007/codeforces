#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxV = 90010;
const int maxN = 3e5+10;
const int inf = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ll INF = 1000000000000000010LL;
#define X first
#define Y second


char s[maxN]; 
pii t[maxN];
int tot = 0;
int n,k;
int main() {
	scanf("%s",s+1);
	tot = 0;
	int n = strlen(s+1);
	int cnt = 1;
	for(int i=2;i<=n;i++)
	{
		if(s[i] != s[i-1])
		{
			t[++tot] = pii(s[i-1],cnt);
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	t[++tot] = pii(s[n],cnt);
	if(tot %2 != 1)
	{
		puts("0");
		return 0;
	}
	else
	{
		int pos = tot/2;
		int flag = 0;
		for(int i=1;i<=pos;i++)
		{
			if(t[i].X == t[tot-i+1].X && t[i].Y + t[tot-i+1].Y >= 3)
			{
				continue;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0 && t[pos+1].Y >= 2)
		{
			printf("%d\n",t[pos+1].Y+1);
			return 0;
		}
		else
		{
			puts("0");
			return 0;
		}
	}
	return 0;
}