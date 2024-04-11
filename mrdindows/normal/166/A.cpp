#include <iostream>
using namespace std;
int main()
{
     int n,k,a[51][3],b[51][3],c=0,x,y;
     cin >> n>>k;
	 for (int i=1;i<=n;i++)
		 cin>>a[i][1]>>a[i][2];
	 for (int i=1;i<=n;i++)
	 {
		 for (int j=1;j<n;j++)
			 if (a[j][1]<=a[j+1][1])
				 if (a[j][1]<a[j+1][1])
				 {
					 x=a[j][1];
					 y=a[j][2];
					 a[j][1]=a[j+1][1];
					 a[j][2]=a[j+1][2];
					 a[j+1][1]=x;
					 a[j+1][2]=y;
				 }
				 else
					 if (a[j][2]>a[j+1][2])
				 {
					 x=a[j][1];
					 y=a[j][2];
					 a[j][1]=a[j+1][1];
					 a[j][2]=a[j+1][2];
					 a[j+1][1]=x;
					 a[j+1][2]=y;
				 }
	 }
	 for (int i=1;i<=n;i++)
		 if (a[i][1]==a[k][1] && a[i][2]==a[k][2]) c++;
	 cout<<c;
     return 0;
}