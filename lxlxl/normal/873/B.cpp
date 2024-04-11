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
#define inf 1e9
using namespace std;

const int maxn = 110000;

int n;
int pos[maxn<<1];
char str[maxn];

int main()
{
	memset(pos,-1,sizeof pos);
	
	scanf("%d",&n); scanf("%s",str+1);
	int k=0,ans=0;
	pos[n]=0;
	for(int i=1;i<=n;i++)
	{
		k+=str[i]=='0'?1:-1;
		if(pos[k+n]!=-1) ans=max(ans,i-pos[k+n]);
		else pos[k+n]=i;
	}
	printf("%d\n",ans);
	
	return 0;
}