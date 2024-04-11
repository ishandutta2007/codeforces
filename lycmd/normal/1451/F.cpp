#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,m,a[N][N],s[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=2;i<=n+m;i++)
			s[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j],s[i+j]^=a[i][j];
		int flg=1;
		for(int i=2;i<=n+m;i++)
			flg&=!s[i];
		cout<<(flg?"Jeel\n":"Ashish\n");
	}
}