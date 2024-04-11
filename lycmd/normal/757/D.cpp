#include<bits/stdc++.h>
using namespace std;
int const N=77,M=1050010,MOD=1000000007;
int n,ans,a[N][N],f[N][M];
string s;
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
int main(){
	cin>>n>>s,s=" "+s;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			if((a[l][r]=a[l][r-1]<<1|(s[r]-48))>20){
				a[l][r]=0;
				break;
			}
	for(int i=0;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int p=1;p<=i;p++)
			if(a[p][i])
				for(int v=a[p][i]-1,j=0;j<M;j++)
					if(j>>v&1)
						add(f[i][j],f[p-1][j]),
						add(f[i][j],f[p-1][j^1<<v]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=20;j++)
			add(ans,f[i][(1<<j)-1]);
	cout<<ans<<"\n";
}