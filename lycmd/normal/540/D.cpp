#include<bits/stdc++.h>
using namespace std;
int const N=105;
int a,b,c;
double f1[N][N][N],f2[N][N][N],f3[N][N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			f1[i][j][0]=1;
	for(int i=1;i<=b;i++)
		for(int j=1;j<=c;j++)
			f2[0][i][j]=1;
	for(int i=1;i<=c;i++)
		for(int j=1;j<=a;j++)
			f3[j][0][i]=1;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++){
				double s=i*j+j*k+k*i,p1=i*j/s,p2=j*k/s,p3=k*i/s;
				f1[i][j][k]=p1*f1[i][j-1][k]+p2*f1[i][j][k-1]+p3*f1[i-1][j][k];
				f2[i][j][k]=p1*f2[i][j-1][k]+p2*f2[i][j][k-1]+p3*f2[i-1][j][k];
				f3[i][j][k]=p1*f3[i][j-1][k]+p2*f3[i][j][k-1]+p3*f3[i-1][j][k];
			}
	cout<<fixed<<setprecision(10)<<f1[a][b][c]<<" "<<f2[a][b][c]<<" "<<f3[a][b][c]<<"\n";
}