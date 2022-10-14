#include<bits/stdc++.h>
using namespace std;
int const N=505,MOD=1000000007;
int n,a[N],f[N][N];
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i][i]=1;
	for(int d=2;d<=n;d++)
		for(int l=1;l<=n-d+1;l++)
			for(int r=l+d-1,p=l+1;p<=r;p++)
				if(p==r||a[l+1]<=a[p+1])
					add(f[l][r],1ll*f[l+1][p]*f[p][r]%MOD);
	cout<<f[1][n]<<"\n";
}