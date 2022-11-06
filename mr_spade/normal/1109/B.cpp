#include<cstdio>
#include<cstring>
const int N=5005;
int n;
char s[N],t[N];
inline bool isp(int l,int r)
{
	register int i,j;
	for(i=l,j=r;i<j;i++,j--)
		if(t[i]!=t[j])
			return 0;
	return 1;
}
signed main()
{
	int f=1;
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=2;i<=n/2;i++)
		f&=(s[i]==s[1]);
	if(f)
		return puts("Impossible"),0;
	for(i=1;i<=n-1;i++)
	{
		memcpy(t+n-i+1,s+1,sizeof(char)*i);
		memcpy(t+1,s+i+1,sizeof(char)*(n-i));
		f=1;
		for(j=1;j<=n;j++)
			f&=(s[j]==t[j]);
		if(f)
			continue;
		if(isp(1,n))
			return puts("1"),0;
	}
	puts("2");
	return 0;
}