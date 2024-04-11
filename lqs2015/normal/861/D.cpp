#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<long long,long long> mp,mpp[77777];
long long hashh,n,mn,cnt;
char s[77777][11],mns[11],cur[11];
int main()
{
	scanf("%d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		for (long long j=0;j<9;j++)
		{
			hashh=0;
			for (long long k=j;k<9;k++)
			{
				hashh=hashh*17+(s[i][k]-'0'+1);
				mp[hashh]++;
				mpp[i][hashh]++;
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		mn=1e9;
		for (long long j=0;j<9;j++)
		{
			hashh=0;cnt=0;
			for (long long k=j;k<9;k++)
			{
				hashh=hashh*17+(s[i][k]-'0'+1);
				cur[cnt++]=s[i][k];
				if (mn<=cnt) break;
				if (mp[hashh]==mpp[i][hashh]) 
				{
					for (long long h=0;h<cnt;h++) mns[h]=cur[h];
					mns[cnt]='\0';
					mn=cnt;
				}
			}
		}
		printf("%s\n",mns);
	}
	return 0;
}