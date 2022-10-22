#include <bits/stdc++.h>
using namespace std;

int query(int x,int y)
{
	cout<<'?'<<' '<<x<<' '<<y<<endl;
	cout<<flush;
	int s;
	cin>>s;
	return s;
}

const int B=1e9;
int main()
{
	int s1=query(1,1),s2=query(1,B),s3=query(B,1),s4=query(B,B);
	int l=1,r=B,res,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if((long long)query(1,mid)+mid-1<=s1)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	assert(res>=1 && res<=B);
	int a=query(1,res)+1,b=res,c=-(s3+1-B-b),d=-(s4-B-B+c);
	cout<<"!"<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cout<<flush;
	return 0;
}