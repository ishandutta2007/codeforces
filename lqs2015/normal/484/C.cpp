#include<bits/stdc++.h>
using namespace std;
char s[1111111],res[1111111];
int n,q,d,k,nxt[1111111],cnt,line[1111111],cur,cyc[1111111],crt,all,cr;
bool used[1111111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&k,&d);
		for (int i=0;i<=k;i++) nxt[i]=0; 
		cnt=0;
		for (int i=0;i<d;i++)
		{
			for (int j=i;j<k;j+=d)
			{
				nxt[j+1]=cnt;
				cnt++;
			}
		}
		for (int i=0;i<=k;i++) used[i]=0;
		cnt=0;
		cur=k;
		while(cur)
		{
			line[++cnt]=cur;
			used[cur]=1;
			cur=nxt[cur];
		}
		reverse(line+1,line+cnt+1);
		all=n-k+1;
		for (int i=1;i<k;i++)
		{
			if (!used[i])
			{
				crt=0;
				for (int j=i;!used[j];j=nxt[j])
				{
					used[j]=1;
					cyc[crt++]=j;
				}
				for (int j=0;j<crt;j++)
				{
					res[n-k+cyc[(j+all)%crt]]=s[cyc[j]-1];
				}
			}
		}
		for (int i=1;i<=cnt && i+k<=n+1;i++)
		{
			res[i-1]=s[line[i]-1];
		}
		for (int i=n-k+2;i<=cnt;i++)
		{
			res[n-k+line[i-(n-k+1)]]=s[line[i]-1];
		}
		for (int i=k;i<=n-cnt;i++)
		{
			res[i+cnt-k]=s[i];
		}
		for (int i=max(n-cnt+1,k);i<n;i++)
		{
			res[n-k+line[cnt-(n-i)]]=s[i];
			cr++;
		}
		for (int i=0;i<n;i++) s[i]=res[i];
		s[n]='\0';
		printf("%s\n",s);
	}
	return 0;
}