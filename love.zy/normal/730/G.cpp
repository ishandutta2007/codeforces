#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct plan
{
  int pos;
  int st,en;
  plan(int st=0,int en=0,int pos=0):st(st),en(en),pos(pos){}
  bool operator < (const struct plan p)const
  {return en<p.st;}
}pl[205];

int a[205],b[205];
int i,j,k,l,m,n;

void cl(int x,int y,int now)
{
  for(int i=m;i>=y;i--)pl[i+1]=pl[i];
  if(now==1)pl[y]=plan(a[x],b[x],x);else pl[y]=plan(pl[y-1].en+1,pl[y-1].en+1+b[x]-a[x],x);
  m++;
}

bool cmp(plan x,plan y)
{return x.pos<y.pos;}

int main() 
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	  scanf("%d%d",&a[i],&b[i]);
	  b[i]=a[i]+b[i]-1;
	}
	pl[0]=plan(0,0,0);
	pl[1]=plan(a[1],b[1],1);
	pl[2]=plan(2e9,2e9,2e9);
	m=2;
	for(i=2;i<=n;i++)
	{
	  struct plan t=plan(a[i],b[i]);
	  k=0;
	  for(j=1;j<=m;j++)
	    if(pl[j-1].en<a[i] && pl[j].st>b[i]){k=j;break;}
	  if(k>0){cl(i,k,1);continue;}
	  for(j=1;j<=m;j++)
	    if(pl[j].st-pl[j-1].en-1>=b[i]-a[i]+1){k=j;break;}
	  cl(i,k,2);
	}
	sort(pl+1,pl+m+1,cmp);
	for(i=1;i<m;i++)printf("%d %d\n",pl[i].st,pl[i].en);
	return 0;
}