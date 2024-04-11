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

const int maxn = 110;
const int maxm = 1100;

int n,v,v1,a,l;

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d%d%d%d",&n,&v,&v1,&a,&l);
	v-=a;
	
	int now=1,ans=0;
	while(++ans)
	{
		v+=a; if(v>v1)v=v1;
		if(now+v-1>=n) break;
		now=now+v-l;
	}
	printf("%d\n",ans);
	
	return 0;
}