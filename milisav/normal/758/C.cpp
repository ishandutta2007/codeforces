#include <iostream>
#include <cstdio>
using namespace std;
long long int n,m,k,x,y,l,r1,r2,r3,p,q;
long long int d[100][100];
int main()
{
	cin>>n>>m>>k>>x>>y;
	x--;
	y--;
	int x1,y1;
	l=(2*n-2)*m;
	if(l==0) l=n*m;
	r1=-1;
	r2=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			r3=0;
			x1=i-1;
			y1=j;
			p=k%l;
			q=k/l;
			r3=q;
			if(x1>0 && x1<n-1) r3=q*2;
			if(x1*m+y1<=p) r3++;
			p=p-n*m;
			x1++;
			x1=n-x1;
			x1--;
			if(x1>=0 && p>=x1*m+y1) r3++;
			d[i-1][j-1]=r3;
			if(d[i-1][j-1]>r1) r1=d[i-1][j-1];
			if(d[i-1][j-1]<r2 || r2==-1) r2=d[i-1][j-1];
		}
	}
	r3=d[x][y];
	cout<<r1<<" "<<r2<<" "<<r3<<endl;
	return 0;
}