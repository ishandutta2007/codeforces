#include <iostream>
//#include <conio.h>
using namespace std;
int main()
{
     int n,k,a[1000],c=0,cmin,cmax,x,y,e=0,s;
     cin >> n>>x;
	 cmin=0;cmax=n+1;
	 for (int i=1;i<=n;i++)
		 cin>>a[i];
	 for (int i=1;i<=n;i++)
	 {
		 for (int j=1;j<n;j++)
				 if (a[j]>a[j+1])
				 {
					swap(a[j],a[j+1]);
				 }
	 }
	 for (int i=1;i<=n;i++)
	 {
		 if (a[i]<x) 
			 cmin=i;
		 if (a[i]>x)
		 {
			
			 cmax=i;
			 break;
		 }
	 }
	 if (cmax-cmin==1) 
	 {cmin=cmax;n++;e=1;}
	 else
	 {cmin++;cmax--;}
	 k=(int) ((n+1)/2);
	 if (k>cmax)
	 {
		 if (n%2==0) cout<<(k-cmax)*2+e;
		 else cout<<(k-cmax)*2-1+e;
	 }
	 else if (k<cmin)
	 {
		 if (n%2==0) cout<<(-k+cmin)*2-1+e;
		 else cout<<(-k+cmin)*2+e;
	 }
	 else cout<<e;
     return 0;
}