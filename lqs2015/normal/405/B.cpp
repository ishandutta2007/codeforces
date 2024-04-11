#include<iostream>
using namespace std;
int n,s,lef,righ,k,i;
char c;
int main()
{
	cin>>n;
	lef=-1;
	righ=-1;
	s=n;
	for (i=1;i<=n;i++)
	{
		cin>>c;
		if (c=='.') continue;
		k=i-righ;
		if (c=='L') 
		{
			if (righ==-1) 
			{
				s-=i;
			}
			else
			{
				if (k%2==0) s=s-k;
				else s=s-k-1;
			}
			lef=i;
		}
		else
		{
			righ=i;
		}
		
	}
	if (righ>lef) s-=(n-righ+1);
	cout<<s<<endl;
	return 0;
}