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
int a[maxn];
pair<int,int> b[maxn];
int n;
int sum;
int lastnum,lastans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=x-y;
		b[i].first=-2*a[i];
		b[i].second=i;
		sum+=a[i];
	}
	sort(b+1,b+n+1);
	lastnum=abs(sum);
	for (int i=1;i<=n;i++)
	if (abs(sum+b[i].first)>lastnum)	lastnum=abs(sum+b[i].first),lastans=b[i].second;
	printf("%d\n",lastans);
	return 0;
}