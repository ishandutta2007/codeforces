#include<iostream>
using namespace std;
long long n,x,y,a[333333],cnt,pos;
char c;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	getchar();
	for (long long i=1;i<=n;i++) 
	{
		c=getchar();
		a[i]=c-'0';
	}
	pos=1;
	while(pos<=n)
	{
		if (a[pos]) 
		{
			pos++;
			continue;
		}
		while(pos<=n && !a[pos]) pos++;
		cnt++;
	}
	if (!cnt) printf("0\n");
	else printf("%I64d\n",(cnt-1)*min(x,y)+y);
	return 0;
}