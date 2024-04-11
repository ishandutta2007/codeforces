#include<bits/stdc++.h>
using namespace std;
int c[101];
double f[101][10001];
int main(){
	int n,m=0;
	double q;
	cin>>n>>q,f[0][0]=1;
	for(int x=1;x<=n;x++)
    cin>>c[x],m+=c[x];
	for(int x=1;x<=n;x++)
    for(int y=x;y>=1;y--)
    for(int z=c[x];z<=m;z++)
    f[y][z]+=f[y-1][z-c[x]]*y/(n-y+1);
    double ans=0;
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++)ans+=f[x][y]*min((n*1.0/x+1)*q/2,y*1.0/x);
	printf("%.16lf",ans);
}