#include <bits\stdc++.h>
using namespace std;
int n;
int a[200000];
int bp=0,bn=-1000000007;
int c,d;
bool fn=false;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	//sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		c=bp;
		d=bn;
		//cout<<a[i]<<" "<<bn<<" "<<bp<<endl;
		if(a[i]>=0)
		{
			if((a[i]&1)==1)
			{
				bn=max(d,a[i]+c);
				bp=max(c,d+a[i]);
				fn=true;
			}
			else
			{
				if(fn) bn=bn+a[i];
				bp=bp+a[i];
			}
		}
		else
		{
			if((a[i]&1)==1)
			{
				bn=max(d,a[i]+c);
				bp=max(c,d+a[i]);
				fn=true;
			}
		}
	}
	printf("%d",bn);
	return 0;
}