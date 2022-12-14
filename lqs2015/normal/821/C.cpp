#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int numr,prev[555555],ans,n,x,cnt;
char c[1111];
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
	{
		scanf("%s",c);
		if (c[0]=='a')
		{
			scanf("%d",&x);
			prev[++cnt]=x;
		}
		else
		{
			if (cnt && prev[cnt]==numr+1) cnt--;
			else if (cnt)
			{
				ans++;
				cnt=0; 
			}
			numr++;
		}
	} 
	printf("%d\n",ans);
	return 0;
}