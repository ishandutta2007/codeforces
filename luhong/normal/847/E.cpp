#include<iostream>
#include<cstdio>
using namespace std;
char c[100100];
int next[100010];
int n;
bool check(int k)
{
	//cout<<endl;
	int last=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='P')
		{
			int zuo=next[last+1];
			if(i-k>zuo)return 0;
			if(zuo>i)last=i+k;
			else if(k-(i-zuo)*2>(k-(i-zuo))/2)last=i+k-(i-zuo)*2;
			else last=max(i,i+(k-(i-zuo))/2);
			if(next[min(last+1,n)]==99999999)return 1;
			//cout<<last<<" ";
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);scanf("%s",c);
	next[n]=99999999;
	for(int i=n-1;i>=0;i--)
	{
		next[i]=next[i+1];
		if(c[i]=='*')next[i]=i;
	}next[n]=99999999;
//	for(int i=0;i<=n;i++)cout<<next[i]<<" ";
	int l=0,r=2*n+1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;return 0;
}