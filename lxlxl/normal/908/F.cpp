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

ll re;
int n;
int a[maxn],b[maxn];

char str[1100];
char ss[110];

int main()
{
	str['G']=0,str['B']=1,str['R']=2;
	scanf("%d",&n);
	int las=0;
	for(int i=1;i<=n;i++)
	{
		int p; scanf("%d",&p); a[i]=p;
		scanf("%s",ss);
		int cc=str[ss[0]]; b[i]=cc;
		if(!cc)
		{
			if(!las)
			{
				if(i!=1)
				{
					int la1=0,la2=0;
					for(int j=1;j<i;j++)
					{
						if(b[j]==1)
						{
							if(la1) re+=a[j]-a[la1];
							la1=j;
						}
						else
						{
							if(la2) re+=a[j]-a[la2];
							la2=j;
						}
					}
					if(la1) re+=a[i]-a[la1];
					if(la2) re+=a[i]-a[la2];
				}
			}
			else
			{
				if(i==las+1) { re+=a[i]-a[las]; }
				else
				{
					int mx1=0,mx2=0;
					int la1=las,la2=las;
					int cc;
					for(int j=las+1;j<i;j++)
					{
						if(b[j]==1) mx1=max(mx1,a[j]-a[la1]),la1=j;
						else mx2=max(mx2,a[j]-a[la2]),la2=j;
					}
					if(la1!=las) cc=a[i]-a[la1],mx1=max(mx1,cc);
					if(la2!=las) cc=a[i]-a[la2],mx2=max(mx2,cc);
					
					if(la1==las||la2==las) re+=2ll*(a[i]-a[las])-mx1-mx2;
					else re+=min(2ll*(a[i]-a[las]),(ll)3*(a[i]-a[las])-(ll)mx1-(ll)mx2);
				}
			}
			las=i;
		}
	}
	if(!las)
	{
		re=0;
		int la1=0,la2=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				if(la1) re+=a[i]-a[la1];
				la1=i;
			}
			if(b[i]==2)
			{
				if(la2) re+=a[i]-a[la2];
				la2=i;
			}
		}
	}
	else
	{
		int la1=0,la2=0;
		for(int i=n;i>las;i--)
		{
			if(b[i]==1)
			{
				if(la1) re+=a[la1]-a[i];
				la1=i;
			}
			else
			{
				if(la2) re+=a[la2]-a[i];
				la2=i;
			}
		}
		if(la1) re+=a[la1]-a[las];
		if(la2) re+=a[la2]-a[las];
	}
	printf("%I64d\n",re);
	
    return 0;
}