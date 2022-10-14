#include<bits/stdc++.h>
using namespace std;
int const N=505;
int n,m,ans,b[N][N],s[N][N];
char a[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],b[i][j]=a[i][j]=='B';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=s[i][j]=b[i][j]^b[i+1][j]^b[i][j+1]^b[i+1][j+1];
	if(s[n][m]){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i-1][j-1]&&s[i-1][m]&&s[n][j-1])
					cout<<ans-1<<"\n",exit(0);
	}
	cout<<ans<<"\n";
}