#include<cstdio>
#include<cstring>
const int N(5e5+5);
int n,x;
char s[10];
int bit[10];
int ans,qie(1023),huo,yihuo;
signed main()
{
	int radix;
	scanf("%d",&n);
	memset(bit,-1,sizeof(bit));
	while(n--)
	{
		scanf("%s",s);
		scanf("%d",&x);
		if(s[0]=='&')
		{
			for(radix=0;radix<10;radix++)
				if(!(x&(1<<radix)))
					bit[radix]=0;
		}
		else if(s[0]=='|')
		{
			for(radix=0;radix<10;radix++)
				if(x&(1<<radix))
					bit[radix]=1;
		}
		else
		{
			for(radix=0;radix<10;radix++)
				if(x&(1<<radix))
				{
					if(bit[radix]==0||bit[radix]==1)
						bit[radix]=!bit[radix];
					else
						bit[radix]=-3-bit[radix];
				}
		}
	}
	for(radix=0;radix<10;radix++)
		if(!bit[radix])
			qie^=1<<radix;
		else if(bit[radix]==1)
			huo|=1<<radix;
		else if(bit[radix]==-2)
			yihuo|=1<<radix;
	if(qie!=1023)
		ans++;
	if(huo)
		ans++;
	if(yihuo)
		ans++;
	printf("%d\n",ans);
	if(qie!=1023)
		printf("& %d\n",qie);
	if(huo)
		printf("| %d\n",huo);
	if(yihuo)
		printf("^ %d\n",yihuo);
	return 0;
}