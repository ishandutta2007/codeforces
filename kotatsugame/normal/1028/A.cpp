#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
string s[555];
int x,y;
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
	{
		int l=114514,r=-1;
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='B')
			{
				l=min(l,j);
				r=max(r,j);
			}
		}
		if(l<=r)
		{
			y=(l+r)/2;
			break;
		}
	}
	int l=114514,r=-1;
	for(int i=0;i<n;i++)
	{
		if(s[i][y]=='B')
		{
			l=min(l,i);
			r=max(r,i);
		}
	}
	x=(l+r)/2;
	cout<<x+1<<" "<<y+1<<endl;
}