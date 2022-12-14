#include<bits/stdc++.h>
using namespace std;
char s[1111111];
int t[2222222],sa[2222222],lcp[2222222],buc[2222222],arr[2222222],k,rnk[2222222],n,cur,tmp[2222222],res,x,y,dp[2222222];
const int ct=2;
int pre[2222222],suf[2222222],mpre[2222222],msuf[2222222];
bool cmp(int i,int j)
{
	int ri=i+k<n ? rnk[i+k] : -1;
	int rj=j+k<n ? rnk[j+k] : -1;
	return (rnk[i]==rnk[j] && ri==rj);
}
void make_sa()
{
	for (int i=0;i<ct;i++) buc[i]=0;
	for (int i=0;i<n;i++) buc[t[i]]++;
	for (int i=1;i<ct;i++) buc[i]+=buc[i-1];
	for (int i=0;i<n;i++) sa[--buc[t[i]]]=i;
	for (int i=0;i<n;i++) rnk[i]=t[i];
	for (k=1;k<=n;k*=2)
	{
		cur=0;
		for (int i=n-k;i<n;i++) arr[cur++]=i;
		for (int i=0;i<n;i++)
		{
			if (sa[i]>=k) arr[cur++]=sa[i]-k;
		}
		for (int i=0;i<n;i++) buc[i]=0;
		for (int i=0;i<n;i++) buc[rnk[i]]++;
		for (int i=1;i<n;i++) buc[i]+=buc[i-1];
		for (int i=n-1;i>=0;i--) sa[--buc[rnk[arr[i]]]]=arr[i];
		tmp[sa[0]]=0;
		for (int i=1;i<n;i++) 
		{
			if (cmp(sa[i-1],sa[i])) tmp[sa[i]]=tmp[sa[i-1]];
			else tmp[sa[i]]=tmp[sa[i-1]]+1;
		}
		for (int i=0;i<n;i++) rnk[i]=tmp[i];
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<2*n;i++)
	{
		if (i>=n) 
		{
			if (s[i-n]=='(') t[i]=0;
			else t[i]=1;
		}
		else
		{
			if (s[i]=='(') t[i]=0;
			else t[i]=1;
		}
	}
	for (int i=0;i<n;i++) pre[i]=pre[i-1]+(t[i] ? -1 : 1);
	for (int i=n-1;i>=0;i--) suf[i]=suf[i+1]+(t[i] ? -1 : 1);
	for (int i=0;i<n;i++)
	{
		mpre[i]=min(mpre[i-1],pre[i]);
	}
	for (int i=n-1;i>=0;i--)
	{
		msuf[i]=min(msuf[i+1]+(t[i] ? -1 : 1),(t[i] ? -1 : 1));
	}
	for (int i=0;i<n;i++)
	{
		dp[i]=min(msuf[i],suf[i]+mpre[i-1]);
	}
	n*=2;
	make_sa();
	n/=2;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='(') x++;
		else y++;
	}
	if (x<y)
	{
		for (int i=0;i<n;i++) dp[i]+=(y-x);
	}
	for (int i=0;i<2*n;i++)
	{
		if (sa[i]<n && dp[sa[i]]>=0) 
		{
			res=sa[i];
			break;
		}
	}
	for (int i=x;i<y;i++) putchar('(');
	for (int i=res;i<res+n;i++)
	{
		if (!t[i]) putchar('(');
		else putchar(')');
	}
	for (int i=y;i<x;i++) putchar(')');
	return 0;
}