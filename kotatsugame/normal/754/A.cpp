#include<iostream>
using namespace std;
main()
{
	int n;cin>>n;
	int a[101];
	for(int i=0;i<n;i++)cin>>a[i];
	a[n]=1;
	int l[100],r[100];
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)l[c]=r[c]=i;
		else
		{
			l[c]=i;
			while(i<n&&a[i]==0)i++;
			if(i!=n)r[c]=i;
			else if(c>0)
			{
				c--;
				r[c]=n-1;
			}
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		c++;
	}
	cout<<"YES"<<endl<<c<<endl;
	for(int i=0;i<c;i++)cout<<l[i]+1<<" "<<r[i]+1<<endl;
}