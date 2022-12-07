#include<bits/stdc++.h>

using namespace std;

char s[100005];
struct tj
{
	int p[53];
}a[100005];
int i,j,k,l,m,n,r;

int cl(char c)
{
	if(c<='Z')return c-64;
	else return c-70;
}

bool succ(int t)
{
	int ii,jj,bj,tot;
	for(ii=n;ii>=t;ii--)
	{
		bj=tot=0;
		for(jj=1;jj<=52;jj++)
		{
			if(a[ii].p[jj]==0)continue;
			if(a[ii].p[jj]<=a[ii-t].p[jj]){bj=1;break;}
			if(a[ii].p[jj]>0)tot++;
		}
		if((bj==0)&(tot==k))return true;
	}
	return false;
}

int main()
{
	scanf("%d\n",&n);
	gets(s+1);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		a[i].p[cl(s[i])]++;
	}
	k=0;
	for(i=1;i<=52;i++)if(a[n].p[i]>0)k++;
	l=1;r=n;
	while(r-l>1)
	{
		m=(l+r)/2;
		if(succ(m))r=m;else l=m;
	}
	if(!succ(l))l++;
	printf("%d",l);
	return 0;
}