#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=1e6+10;
int n,k,L,R;
int p[N];
bool f[N],flag;
int main()
{
	int T,x;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);L=R=0;
		for(int i=1;i<=n;++i) f[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&k);flag=0;
			for(int j=1;j<=k;++j) scanf("%d",&p[j]);
			for(int j=1;j<=k;++j)
			{
				if(!f[p[j]])
				{
					flag=1;
					f[p[j]]=1;
					break;
				}
			}
			if(flag==0&&L==0) L=i; 
		}
		for(int i=1;i<=n;++i) if(!f[i]) R=i;
		if(L&&R) printf("IMPROVE\n%d %d\n",L,R);
		else printf("OPTIMAL\n");
	} 
	return 0;
}