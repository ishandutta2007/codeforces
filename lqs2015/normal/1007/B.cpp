#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int num[111111],test,a,b,c,cnt[11],ans;
bool can[11][11][11];
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	for (int i=1;i<=100000;i++)
	{
		for (int j=1;j<=sqrt(i);j++)
		{
			if (i%j==0)
			{
				if (j*j!=i) num[i]+=2;
				else num[i]++;
			}
		}
	}
	for (int i=1;i<8;i++)
	{
		for (int j=1;j<8;j++)
		{
			for (int k=1;k<8;k++)
			{
				if (i&1 && j&2 && k&4) can[i][j][k]=1;
				if (i&2 && j&1 && k&4) can[i][j][k]=1;
				if (i&1 && j&4 && k&2) can[i][j][k]=1;
				if (i&2 && j&4 && k&1) can[i][j][k]=1;
				if (i&4 && j&1 && k&2) can[i][j][k]=1;
				if (i&4 && j&2 && k&1) can[i][j][k]=1;
			}
		}
	}
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&a,&b,&c);
		cnt[1]=num[a]-num[gcd(a,b)]-num[gcd(a,c)]+num[gcd(gcd(a,b),c)];
		cnt[2]=num[b]-num[gcd(a,b)]-num[gcd(b,c)]+num[gcd(gcd(a,b),c)];
		cnt[4]=num[c]-num[gcd(a,c)]-num[gcd(b,c)]+num[gcd(gcd(a,b),c)];
		cnt[3]=num[gcd(a,b)]-num[gcd(gcd(a,b),c)];
		cnt[5]=num[gcd(a,c)]-num[gcd(gcd(a,b),c)];
		cnt[6]=num[gcd(b,c)]-num[gcd(gcd(a,b),c)];
		cnt[7]=num[gcd(gcd(a,b),c)];
		ans=0;
		for (int i=1;i<8;i++)
		{
			for (int j=1;j<8;j++)
			{
				for (int k=1;k<8;k++)
				{
					if (can[i][j][k])
					{
						if (i!=j && j!=k && i!=k) ans+=(cnt[i]*cnt[j]*cnt[k]);
						else if (i==j && j==k) ans+=(cnt[i]*(cnt[j]+1)*(cnt[k]+2));
						else if (i==j) ans+=(cnt[i]*(cnt[j]+1)*cnt[k]);
						else if (j==k) ans+=(cnt[i]*cnt[j]*(cnt[k]+1));
						else ans+=(cnt[i]*cnt[j]*(cnt[k]+1));
					}
				}
			}
		}
		printf("%d\n",ans/6);
	}
	return 0;
}