#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long arr[111111],a,b,c,d,x,y,z,cur,ans[111111],pos;
long long can(long long n)
{
	for (long long i=1;i<=100000;i++)
	{
		if (arr[i]==n) return i;
	}
	return -1;
}
void out()
{
	cout<<"Impossible"<<endl;
	exit(0);
}
int main()
{
	cin>>a>>b>>c>>d;
	for (long long i=1;i<=100000;i++) arr[i]=i*(i-1)/2;
	x=can(a+b+c+d);
	if (x==-1) out();
	y=can(a);z=can(d);
	if (y==-1 || z==-1) out();
	if (y+z!=x)
	{
		if (y==1 && z==x) y=0;
		else if (y==0 && z==x-1) y=1;
		else if (z==0 && y==x-1) z=1;
		else if (z==1 && y==x) z=0;
		else out(); 
	}
	cur=c;
	for (long long i=1;i<=y;i++) ans[i]=0;
	for (long long i=y+1;i<=y+z;i++) ans[i]=1;
	pos=y+1;
	while(cur>0)
	{
		if (cur<y) 
		{
			swap(ans[pos],ans[pos-cur]);
			break;
		}
		cur-=y;
		swap(ans[pos],ans[pos-y]);
		pos++;
	}
	for (long long i=1;i<=x;i++) printf("%I64d",ans[i]);
	printf("\n");
	return 0;
}