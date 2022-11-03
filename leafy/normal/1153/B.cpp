#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,H;
int a[N],b[N],c[N][N],h[N][N];
int main(){
	cin>>n>>m>>H;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++){
			if(c[i][j]==0) continue;
			h[i][j]=min(a[j],b[i]);
		}
	for(int i=1;i<=n;i++){
	
		for(int j=1;j<=m;j++)
			cout<<h[i][j]<<' ';
			cout<<endl;
		}
	return 0;
}