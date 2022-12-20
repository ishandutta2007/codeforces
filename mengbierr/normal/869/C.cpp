#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ri register int
long long mod=998244353;
long long f[5005][5005];
int main(){
	for(ri i=1;i<=5000;i++)
	f[1][i]=i+1;
	for(ri i=2;i<=5000;i++)
	for(ri j=1;j<=5000;j++)
	if(j<i)f[i][j]=f[j][i];
	else{
		f[i][j]+=j*f[i-1][j-1]%mod;
		f[i][j]%=mod;
		f[i][j]+=f[i-1][j];
		f[i][j]%=mod;
	}
	long long a,b,c;
	cin>>a>>b>>c;
	long long ans=f[a][b]*f[b][c]%mod*f[c][a]%mod;
	cout<<ans;
}