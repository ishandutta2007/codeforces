#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=1e5+10;
int n,m,k;
char s[N];
int main()
{
	int x,y,cnt=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i) scanf("%d%d",&x,&y);
	for(int i=1;i<=k;++i) scanf("%d%d",&x,&y);
	for(int i=1;i<n;++i) s[++cnt]='U';
	for(int i=1;i<m;++i) s[++cnt]='L';
	x=1;y=1;
	for(int i=1;i<=n;++i)
	{
		if(y==1)
		{
			while(y<m) 
			{
				s[++cnt]='R';++y;
			}
		}
		else if(y==m)
		{
			while(y>1) 
			{
				s[++cnt]='L';
				--y;
			}
		}
		++x;s[++cnt]='D';
	}
	printf("%d\n",cnt-1);
	for(int i=1;i<cnt;++i) putchar(s[i]);puts("");
	return 0;
}