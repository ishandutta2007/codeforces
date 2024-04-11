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

#define maxn 200010
int a[maxn];
int n,m;
int b[maxn],c[maxn];
int que[maxn];
int mjy[maxn];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=m;i++)	read(c[i]),read(b[i]);
	int now=1;
	que[1]=m;
	for (int i=m-1;i>=1;i--)
	if (b[i]>b[que[now]])	que[++now]=i;
	sort(a+1,a+b[que[now]]+1);
	for (int i=b[que[now]]+1;i<=n;i++)	mjy[i]=a[i];
	int l=1,r=b[que[now]],haha=b[que[now]];
	for (int i=now;i>=1;i--)
	{
		for (int j=1;j<=b[que[i]]-b[que[i-1]];j++)
		{
			if (c[que[i]]==1)	mjy[haha]=a[r--];else mjy[haha]=a[l++];
			haha--;
		}
	}
	for (int i=1;i<=n;i++)	printf("%d ",mjy[i]);
	printf("\n");
	return 0;
}