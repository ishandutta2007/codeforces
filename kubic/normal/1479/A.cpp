#include <bits/stdc++.h>
using namespace std;
#define N 100005 
int n,l,r,a[N];
int qry(int x)
{
	if(x<1 || x>n) return 1e9;int res;
	printf("? %d\n",x);fflush(stdout);
	scanf("%d",&res);return res;
} 
int main()
{
	scanf("%d",&n);l=1;r=n;
	while(l<=r)
	{
		int mid=(l+r)/2,t1,t2,t3;
		t1=qry(mid-1);t2=qry(mid);t3=qry(mid+1);
		if(t1>t2 && t3>t2)
		{printf("! %d\n",mid);fflush(stdout);return 0;}
		else if(t1<t2) r=mid-1;else l=mid+1;
	}return 0;
}