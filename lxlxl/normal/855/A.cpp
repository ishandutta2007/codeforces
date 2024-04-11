#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210;

int n,m;
char str[maxn][maxn];
int len[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",str[i]);
		len[i]=strlen(str[i]);
		bool flag=true;
		for(int j=1;j<i;j++) if(len[j]==len[i])
		{
			bool now=true;
			for(int l=0;l<len[i];l++) if(str[j][l]!=str[i][l]) { now=false; break; }
			if(now) { flag=false; break; }
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	
    return 0;
}