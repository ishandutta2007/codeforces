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

#define maxn 1000010
const int mo=1e9+7;
char a[maxn];
int pre[30];
int f[maxn<<1];
int n,m,k;
int main()
{
	read(n),read(k);
	scanf("%s",a+1);
	m=strlen(a+1);
	for (int i=1;i<=m;i++)
	{
		if (pre[a[i]-'a'+1]==0)	f[i]=(f[i-1]*2+1)%mo;else f[i]=(1LL*f[i-1]*2-f[pre[a[i]-'a'+1]-1]+mo)%mo;
		pre[a[i]-'a'+1]=i;
	}
	for (int i=m+1;i<=n+m;i++)
	{
		int minx=1<<30,pos=0;
		for (int j=1;j<=k;j++)
		if (pre[j]<minx)	minx=pre[j],pos=j;
		if (minx==0)	f[i]=(f[i-1]*2+1)%mo;else f[i]=(1LL*f[i-1]*2-f[minx-1]+mo)%mo;
		pre[pos]=i;
	}
	f[n+m]=(f[n+m]+1)%mo;
	printf("%d\n",f[n+m]);
	return 0;
}