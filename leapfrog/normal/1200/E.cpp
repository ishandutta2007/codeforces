#include<bits/stdc++.h>
using namespace std;
int n,l,al,ct,mn,nxt[1000005];char c[1000005],a[1000005];
int main()
{
	scanf("%d",&n);
	for(int g=1;g<=n;g++)
	{
		scanf("%s",c+1),l=strlen(c+1),mn=min(al,l),ct=l,nxt[0]=nxt[1]=0,c[++ct]='*';
		for(int i=1;i<=mn;i++) c[++ct]=a[al-mn+i];
//		for(int i=1;i<=ct;i++) printf("%c%c",c[i],i==ct?'\n':' ');
		for(int i=2,k=0;i<=ct;i++)
		{
			while(k&&c[i]!=c[k+1]) k=nxt[k];
			if(c[i]==c[k+1]) nxt[i]=++k;else nxt[i]=k;
		}
//		for(int i=1;i<=ct;i++) printf("%d%c",nxt[i],i==ct?'\n':' ');
		for(int i=nxt[ct]+1;i<=l;i++) a[++al]=c[i];
	}
	for(int i=1;i<=al;i++) putchar(a[i]);
	return puts(""),0;
}