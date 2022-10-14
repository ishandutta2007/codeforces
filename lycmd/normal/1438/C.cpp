#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,m,a[N][N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j],a[i][j]+=(a[i][j]&1)^(i+j&1);
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
	}
}