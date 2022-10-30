#include<bits/stdc++.h>
using namespace std;
struct node{int c,w;bool operator<(node b) const {return w<b.w;}}a[35];
int n,k,t[35];char c[100005];
int main()
{
	scanf("%s%d",c+1,&k),n=strlen(c+1),memset(t,0,sizeof(t));
	if(k>=n) return puts("0\n"),0;
	for(int i=1;i<=n;i++) t[c[i]-'a']++;
	for(int i=0;i<26;i++) a[i]=(node){i,t[i]};
	sort(a,a+26);
	for(int i=0;i<26;i++)
	{
		if(k<a[i].w) break;else k-=a[i].w;
		for(int j=1;j<=n;j++) if(c[j]-'a'==a[i].c) c[j]='*';
	}
	memset(t,0,sizeof(t)),k=0;
	for(int i=1;i<=n;i++) if(c[i]!='*') t[c[i]-'a']=1;
	for(int i=0;i<26;i++) k+=t[i];
	printf("%d\n",k);
	for(int i=1;i<=n;i++) if(c[i]!='*') putchar(c[i]);
	return puts(""),0;
}