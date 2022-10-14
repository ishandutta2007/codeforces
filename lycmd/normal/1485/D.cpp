#include<bits/stdc++.h>
using namespace std;
int const N=505;
int n,m,a[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<720720-((i+j)%2?0:a[i][j]*a[i][j]*a[i][j]*a[i][j])<<" ";
}