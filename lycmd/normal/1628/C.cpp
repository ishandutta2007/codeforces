#include<bits/stdc++.h>
using namespace std;
int const N=1010;
int t,n,a[N][N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		int ans=0;
		for(int i=3;i<=n;i+=4)
			for(int x=1,y=i;y>=1;x+=2,y-=2)
				ans^=a[x][y]^a[x][n-y+1];
		for(int i=n;i>=1;i-=4)
			for(int x=n,y=i;y<=n;x-=2,y+=2)
				ans^=a[x][y]^a[x][n-y+1];
		cout<<ans<<"\n";
	}
}