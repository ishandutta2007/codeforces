#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,m;
int a[maxn];
struct node
{
	int type,l,r;
	node(){}
	node(const int _type,const int _l,const int _r){type=_type;l=_l;r=_r;}
}b[maxn];
int q;

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int t,x,y; scanf("%d%d%d",&t,&x,&y);
		b[i]=node(t,x,y);
	}
	for(int i=1;i<=q;i++)
	{
		if(i!=1) putchar(' ');
		int x; scanf("%d",&x);
		for(int j=m;j>=1;j--) if(b[j].l<=x&&x<=b[j].r)
		{
			if(b[j].type==1)
			{
				if(x==b[j].l) x=b[j].r;
				else --x;
			}
			else x=b[j].r-(x-b[j].l);
		}
		printf("%d",a[x]);
	}puts("");
	
	return 0;
}