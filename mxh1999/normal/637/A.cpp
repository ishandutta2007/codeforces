//meng meng da mjy >w<
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

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

#define maxn 1010
int a[maxn];
int num[maxn];
int q[maxn];
int n,m;
int maxx,mjy;
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]),num[i]=a[i];
	sort(num+1,num+n+1);
	m=unique(num+1,num+n+1)-(num+1);
	for (int i=1;i<=n;i++)	a[i]=lower_bound(num+1,num+m+1,a[i])-num;
	maxx=0;
	for (int i=1;i<=n;i++)
	{
		q[a[i]]++;
		if (q[a[i]]>maxx)	maxx=q[a[i]],mjy=a[i];
	}
	printf("%d\n",num[mjy]);
	return 0;
}