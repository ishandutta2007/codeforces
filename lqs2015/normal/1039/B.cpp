#include<bits\stdc++.h>
using namespace std;
long long n,k,l,r,mid,x;
string s;
int main()
{
	srand(time(0));
	scanf("%I64d%I64d",&n,&k);
	l=1;r=n;
	for (long long i=1;i<=4500;i++)
	{
		if (r-l<=40)
		{
			x=rand()%(r-l+1)+l;
			printf("%I64d %I64d\n",x,x);
			fflush(stdout);
			cin>>s;
			if (s=="Yes")
			{
				return 0;
			}
			else 
			{
				l=max(1ll,l-k);
				r=min(n,r+k);
			}
		}
		else
		{
			mid=(l+r)/2;
			printf("%I64d %I64d\n",l,mid);
			fflush(stdout);
			cin>>s;
			if (s=="Yes") 
			{
				l=max(1ll,l-k);
				r=min(mid+k,n);
			}
			else
			{
				l=max(1ll,mid+1-k);
				r=min(r+k,n);
			}
		}
	}
}