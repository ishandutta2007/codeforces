#include<iostream>
#include<string>
using namespace std;
int n1,m1,n2,m2,mx,mxx,mxy,cur;
string b1[55],b2[55];
int main()
{
	cin>>n1>>m1;
	for (int i=0;i<n1;i++)
	{
		cin>>b1[i];
	}
	cin>>n2>>m2;
	for (int i=0;i<n2;i++)
	{
		cin>>b2[i];
	}
	for (int x=-50;x<=50;x++)
	{
		for (int y=-50;y<=50;y++)
		{
			cur=0;
			for (int i=0;i<n1;i++)
			{
				for (int j=0;j<m1;j++)
				{
					if (i+x>=n2 || i+x<0 || j+y>=m2 || j+y<0) continue;
					cur=cur+(b1[i][j]-'0')*(b2[i+x][j+y]-'0');
				}
			}
			if (cur>mx)
			{
				mx=cur;
				mxx=x;
				mxy=y;
			}
		}
	}
	cout<<mxx<<" "<<mxy<<endl;
	return 0;
}