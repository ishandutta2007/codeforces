#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
int QA(int x1,int y1,int x2,int y2)
{
	int t;
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%d",&t);
	return t;
}

int pdud(int n)
{
	int l=1,r=n;
	int mid,ans1,ans2;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans1=QA(1,1,mid,n);
		ans2=QA(mid+1,1,n,n);
		if(ans1==1 && ans2==1)return mid;
		if(ans1==2 || ans2==0)r=mid;else l=mid;
	}
	ans1=QA(1,1,l,n);
	ans2=QA(r,1,n,n);
	if(ans1*ans2==1)return l;else return -1;
}

int pdlr(int n)
{
	int l=1,r=n;
	int mid,ans1,ans2;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans1=QA(1,1,n,mid);
		ans2=QA(1,mid+1,n,n);
		if(ans1==1 && ans2==1)return mid;
		if(ans1==2 || ans2==0)r=mid;else l=mid;
	}
	ans1=QA(1,1,n,l);
	ans2=QA(1,r,n,n);
	if(ans1*ans2==1)return l;else return -1;
}

int row[2][2],col[2][2];

void find(int r1,int c1,int r2,int c2,int t)
{
	//
	int l=r1,r=r2;
	int mid,ans;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans=QA(mid,c1,r2,c2);
		if(ans>0)l=mid;else r=mid;
	}
	ans=QA(r,c1,r2,c2);
	if(ans==1)row[t][0]=r;else row[t][0]=l;

	//
	l=row[t][0],r=r2;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans=QA(row[t][0],c1,mid,c2);
		if(ans>0)r=mid;else l=mid;
	}
	ans=QA(row[t][0],c1,l,c2);
	if(ans==1)row[t][1]=l;else row[t][1]=r;

	//
	l=c1,r=c2;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans=QA(row[t][0],mid,row[t][1],c2);
		if(ans>0)l=mid;else r=mid;
	}
	ans=QA(row[t][0],r,row[t][1],c2);
	if(ans==1)col[t][0]=r;else col[t][0]=l;

	//
	l=col[t][0],r=c2;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		ans=QA(row[t][0],col[t][0],row[t][1],mid);
		if(ans>0)r=mid;else l=mid;
	}
	ans=QA(row[t][0],col[t][0],row[t][1],l);
	if(ans==1)col[t][1]=l;else col[t][1]=r;

}

int main()
{
	int n;
	scanf("%d",&n);
	int r1=pdud(n);
	if(r1<0)
	{
		int u1=pdlr(n);
		find(1,1,n,u1,0);
		find(1,u1+1,n,n,1);
	}else
	{
		find(1,1,r1,n,0);
		find(r1+1,1,n,n,1);
	}
	printf("! %d %d %d %d",row[0][0],col[0][0],row[0][1],col[0][1]);
	printf(" %d %d %d %d\n",row[1][0],col[1][0],row[1][1],col[1][1]);
    return 0;
}