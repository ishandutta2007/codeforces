#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
char s[maxn],a[maxn<<1];
int p[maxn<<1];
int mid[maxn];
int fail[maxn],front[maxn],ans[maxn];
int n,m;

void kmp()
{
	int j=0;
	for (int i=2;i<=n;i++)
	{
		while (j && a[j+1]!=a[i])	j=fail[j];
		if (a[j+1]==a[i])	j++;
		fail[i]=j;
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)	a[i*2-1]='#',a[i*2]=s[i];
	a[n*2+1]='#';
	a[0]='$';
	int posr=0,posl=0;
	for (int i=1;i<=2*n+1;i++)
	{
		if (posr<i)
		{
			int r=i,l=i;
			while (a[r+1]==a[l-1])	r++,l--;
			p[i]=r-l+1;
			posr=r,posl=l;
		}	else
		{
			int pos=posl+posr-i;
			p[i]=p[pos];
			int r=i+p[pos]/2,l=i-p[pos]/2;
			if (r>posr)	r=posr,l=2*i-r;
			while (a[r+1]==a[l-1])	r++,l--;
			p[i]=r-l+1;
			if (posr<r)	posr=r,posl=l;
		}
	}
	for (int i=1;i<=2*n+1;i++)
	if (i%2==0)	mid[i/2]=p[i]/2;
	memset(a,0,sizeof(a));
	a[0]='$';
	for (int i=1;i<=n;i++)	a[n-i+1]=s[i];
	kmp();
	int j=0;
	for (int i=1;i<=n;i++)
	{
		while (j && a[j+1]!=s[i])	j=fail[j];
		if (a[j+1]==s[i])	j++;
		front[i]=j;
	}
	ans[1]=1;
	for (int i=2;i<=n;i++)
	if (front[i-1]>=front[i])	front[i]=front[i-1],ans[i]=ans[i-1];else ans[i]=i;
	int mjy=0,mmd=0,xmm=0,mxh=0;
	for (int i=1;i<=n;i++)
	{
		int l=i-mid[i]/2,r=i+mid[i]/2;
		l--,r++;
		int num=mid[i]+min(n-r+1,front[l])*2;
		if (mjy<num)	mjy=num,mmd=i,xmm=ans[l],mxh=min(n-r+1,front[l]);
	}
	if (mid[mmd]==mjy)
	{
		printf("1\n");
		int l=mmd-mid[mmd]/2;
		printf("%d %d\n",l,mid[mmd]);
		return 0;
	}
	printf("3\n");
	printf("%d %d\n",xmm-front[xmm]+1,mxh);
	printf("%d %d\n",mmd-mid[mmd]/2,mid[mmd]);
	printf("%d %d\n",n-mxh+1,mxh);
	return 0;
}