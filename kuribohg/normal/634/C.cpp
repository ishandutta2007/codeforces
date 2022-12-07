#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,k,a,b,q,N,wa[MAXN],wb[MAXN];
int BIT[MAXN];
void Change(int x,int tar)
{
	for(int i=x;i<=N;i+=(i&(-i)))
		BIT[i]+=tar;
}
int Query(int x)
{
	int res=0;
	for(int i=x;i;i^=(i&(-i)))
		res+=BIT[i];
	return res;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	N=n-k+1;
	while(q--)
	{
		int op,d,c;
		scanf("%d%d",&op,&d);
		if(op==1) scanf("%d",&c);
		if(op==1)
		{
			int da,db;
			da=min(a,wa[d]+c)-wa[d];
			db=min(b,wb[d]+c)-wb[d];
			wa[d]=min(a,wa[d]+c);
			wb[d]=min(b,wb[d]+c);
			if(d-k>0)
			{
				Change(1,da);
				Change(d-k+1,-da);
			}
			Change(d+1,db);
		}
		else printf("%d\n",Query(d));
	}
	return 0;
}