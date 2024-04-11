#include<bits/stdc++.h>
#define re register
char ss[5001000],ss1[5001000],as[5001000],nw[10001000];
int s[5000100],u[5001000],nm,n1,nx[5001000],lcp[5001000];
void bg(char*a,char*b)
{
	re bool cp=0;
	for(re int i=1;i<=n1;i++)if(a[i]!=b[i]){cp=(a[i]>b[i]);break;}
	if(cp)memcpy(a+1,b+1,n1*sizeof(char));
}
void exkmp(re int n)
{
	nx[1]=n;
	re int i1=2,j1;
	while(nx[2]+2<=n&&ss1[2+nx[2]]==ss1[1+nx[2]])nx[2]++;j1=nx[2]+1;
	for(re int i=3;i<=n;i++)
	{
		if(i+nx[i-i1+1]-1<j1)nx[i]=nx[i-i1+1];
		else
		{
			nx[i]=std::max(j1-i+1,0);i1=i;
			while(nx[i]+i<=n&&ss1[i+nx[i]]==ss1[nx[i]+1])nx[i]++;
			j1=i+nx[i]-1;
		}
	}
	i1=1;
	while(lcp[1]+1<=n&&ss1[lcp[1]+1]==ss[lcp[1]+1])lcp[1]++;
	j1=lcp[1];
	for(re int i=2;i<=n;i++)
	{
		if(i+nx[i-i1+1]-1<j1)lcp[i]=nx[i-i1+1];
		else
		{
			lcp[i]=std::max(j1-i+1,0);i1=i;
			while(lcp[i]+i<=n&&ss[i+lcp[i]]==ss1[lcp[i]+1])lcp[i]++;
			j1=i+lcp[i]-1;
		}
	}
}
int main()
{
	re int n,k,ta=0;
	scanf("%s%d",ss+1,&k);
	n=strlen(ss+1);
	memcpy(ss1,ss,sizeof(ss));
	std::reverse(ss1+1,ss1+n+1);
	if(k==1){n1=n;bg(ss,ss1);puts(ss+1);return 0;}
	for(re int i=1;i<=n;)
	{
		re int j=i,k=i+1;
		for(;k<=n&&ss1[k]>=ss1[j];j++,k++)if(ss1[k]>ss1[j])j=i-1;
		re int i1=i;
		while(i<=j)i+=k-j;
		s[++ta]=i-1;u[ta]=1;
		for(re int ii=1;ii<=i-i1;ii++)if(ss1[i1+ii-1]!=ss1[i-ii]){u[ta]=0;break;}
	}
	for(;ta&&k>=3;ta--){std::reverse(ss+n-s[ta]+1,ss+n-s[ta-1]+1);if(!u[ta]||!u[ta-1])k--;}
	if(!ta||s[ta]==1){puts(ss+1);return 0;}
	re int fr=n-s[ta]+1;n1=s[ta];
	for(re int i=fr;i<=n;i++)as[i-fr+1]=ss[i];
	for(re int i=1;i<=2*n1;i++)nw[i]=ss1[(i-1)%n1+1];
	re int i1=1,j1=2;
	while(i1<=n1&&j1<=n1)
	{
		re int k=0;for(;k<n1&&nw[i1+k]==nw[j1+k];k++);
		if(nw[i1+k]>nw[j1+k])i1+=k+1;
		else j1+=k+1;if(i1==j1)i1++;
	}i1=std::min(i1,j1);
	for(re int i=1;i<=n1;i++)nw[i]=nw[i+i1-1];
	bg(as,nw);
	exkmp(n);
	re int bt=0;
	for(re int j=1;j<=n1;j++)
	{
		if(lcp[fr+bt]<j-bt)
		{
			if(ss[fr+bt+lcp[fr+bt]]<ss1[lcp[fr+bt]+1])bt=j;
		}else if(nx[j-bt+1]<n-j)
		{
			if(ss1[nx[j-bt+1]+1]<ss1[nx[j-bt+1]+j-bt+1])bt=j;
		}
	}
	for(re int i=1;i<=n1;i++)nw[i]=ss[fr+i-1];
	std::reverse(nw+bt+1,nw+n1+1);
	bg(as,nw);
	i1=ta;
	for(;i1>1;i1--)
	{
		re int j1=1,len=s[ta]-s[i1-1],cp=0;
		for(;j1<=len;j1++)if(ss1[s[i1-1]+j1]!=ss1[s[i1-2]+j1])break;
		if(j1<=len)break;
		for(j1=1;j1+len<=s[ta]-s[i1-2];j1++)if(ss[fr+len+j1-1]!=ss1[s[i1-2]+j1+len]){cp=(ss[fr+len+j1-1]<ss1[s[i1-2]+j1+len]);break;}
		if(cp)break;
	}
	for(re int i=1;i<=n1;i++)nw[i]=ss[fr+i-1];
	std::reverse(nw+1,nw+n1-s[i1-1]+1);
	bg(as,nw);
	for(re int i=1;i<=n1;i++)ss[i+fr-1]=as[i];
	puts(ss+1);
}