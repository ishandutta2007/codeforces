#include<bits/stdc++.h>
using namespace std;
int const N=1010;
int n,m,x,y;
double f[2][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>x>>y;
	for(int i=n-1;i>=x;i--)
		for(int o=i&1,t=40;t--;)
			if(m>1){
				f[o][1]=(f[o][1]+f[o][2]+f[!o][1])/3+1;
				f[o][m]=(f[o][m]+f[o][m-1]+f[!o][m])/3+1;
				for(int j=2;j<m;++j)
					f[o][j]=(f[o][j]+f[o][j-1]+f[o][j+1]+f[!o][j])/4+1;
			}else f[o][1]=(f[o][1]+f[!o][1])/2+1;
	cout<<fixed<<setprecision(6)<<f[x&1][y]<<"\n";
}