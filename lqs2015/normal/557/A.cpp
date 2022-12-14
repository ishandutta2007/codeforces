#include<iostream>
using namespace std;
int main()
{
	int n,mn[3],mx[3],d[3];
	cin>>n>>mn[0]>>mx[0]>>mn[1]>>mx[1]>>mn[2]>>mx[2];
	for (int i=n-mn[1]-mn[2];i>=mn[0];i--)
	{
		if (i>mx[0]) continue;
		d[0]=i;
		for (int j=n-d[0]-mn[2];j>=mn[1];j--)
		{
			if (j>mx[1]) continue;
			d[1]=j;
			d[2]=n-d[0]-d[1];
			if (d[2]<=mx[2] && d[2]>=mn[2])
			{ 
			    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" ";
			    return 0;
		    } 
		}
	}
	return 0;
}