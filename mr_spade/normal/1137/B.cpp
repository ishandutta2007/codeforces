#include<cstdio>
#include<cstring>
const int N=5e5+5;
int n,m;
int cnt[2];
char s[N],t[N];
int next[N];
int epc[2],pc[2];
signed main()
{
	register int i,j;
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	for(i=1;i<=n;i++)
		cnt[s[i]-'0']++;
	next[0]=-1;
	for(i=1;i<=m;next[i]=j+1,i++)
		for(j=next[i-1];~j&&t[j+1]!=t[i];j=next[j]);
	for(i=1;i<=m;i++)
		epc[t[i]-'0']++;
	for(i=next[m]+1;i<=m;i++)
		pc[t[i]-'0']++;
	if(cnt[0]<epc[0]||cnt[1]<epc[1])
		return printf("%s\n",s+1),0;
	printf("%s",t+1);cnt[0]-=epc[0];cnt[1]-=epc[1];
	while(cnt[0]>=pc[0]&&cnt[1]>=pc[1])
	{
		for(i=next[m]+1;i<=m;i++)
			putchar(t[i]);
		cnt[0]-=pc[0];cnt[1]-=pc[1];
	}
	while(cnt[0]--)
		putchar('0');
	while(cnt[1]--)
		putchar('1');
	putchar('\n');
	return 0;
}