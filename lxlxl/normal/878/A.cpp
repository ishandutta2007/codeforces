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

const int maxn = 510000;

int n;
int a[20],b[20];
char str[110];

int cc[3];

int main()
{
	scanf("%d",&n);
	memset(a,-1,sizeof a);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str); int x;scanf("%d",&x);
		if(str[0]=='|')
		{
			for(int j=0;j<10;j++) if(x>>j&1)
				a[j]=1,b[j]=0;
		}
		else if(str[0]=='&')
		{
			for(int j=0;j<10;j++) if(!(x>>j&1))
				a[j]=0,b[j]=0;
		}
		else
		{
			for(int j=0;j<10;j++) if(x>>j&1)
				b[j]=!b[j];
		}
	}
	int k=0; cc[0]=cc[1]=cc[2]=-1;
	for(int i=0;i<10;i++) if(a[i]==1)
	{
		if(cc[0]==-1) cc[0]=1<<i;
		else cc[0]|=1<<i;
	}
	for(int i=0;i<10;i++) if(a[i]==0)
	{
		if(cc[1]==-1) cc[1]=1023-(1<<i);
		else cc[1]-=1<<i;
	}
	for(int i=0;i<10;i++) if(b[i])
	{
		if(cc[2]==-1) cc[2]=1<<i;
		else cc[2]|=1<<i;
	}
	for(int i=0;i<3;i++) if(cc[i]!=-1) k++;
	printf("%d\n",k);
	if(cc[0]!=-1) printf("| %d\n",cc[0]);
	if(cc[1]!=-1) printf("& %d\n",cc[1]);
	if(cc[2]!=-1) printf("^ %d\n",cc[2]);
	
	return 0;
}