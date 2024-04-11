#include<cstdio>
#include<cstring>
#define int long long
const int N=1e5+5;
int n,m;
char s[N];
int cnt[6];
int belong[N];
int sum[64][N];
inline bool check(int x)
{
	int res;
	register int i,j;
	for(i=0;i<64;i++)
	{
		res=0;
		for(j=0;j<6;j++)
			if(i>>j&1)
				res+=cnt[j];
		if(sum[i][n]-sum[i][x]<res)
			return 0;
	}
	return 1;
}
signed main()
{
	int pos,k;
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		cnt[s[i]-'a']++;
	for(i=1;i<=n;i++)
		belong[i]=63;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%s",&pos,s+1);
		belong[pos]=0;k=strlen(s+1);
		for(j=1;j<=k;j++)
			belong[pos]|=1<<(s[j]-'a');
	}
	for(i=0;i<64;i++)
		for(j=1;j<=n;j++)
			if(belong[j]&i)
				sum[i][j]=sum[i][j-1]+1;
			else
				sum[i][j]=sum[i][j-1];
	if(!check(0))
		return puts("Impossible"),0;
	for(i=1;i<=n;i++)
		for(j=0;j<6;j++)
			if(belong[i]>>j&1)
			{
				cnt[j]--;
				if(check(i))
				{
					s[i]=j+'a';
					break;
				}
				cnt[j]++;
			}
	s[n+1]='\0';
	printf("%s\n",s+1);
	return 0;
}