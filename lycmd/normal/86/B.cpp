#include<bits/stdc++.h>
using namespace std;
int const N=1010,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m;
char a[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]=='.'&&a[i][j+1]=='.')
				a[i][j]=a[i][j+1]=i%3*3+(j+(i+j)%2)%3+48;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='.'&&a[i+1][j]=='.')
				a[i][j]=a[i+1][j]=i%3*3+(j+(i+j)%2)%3+48;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='.'){
				for(int d=0;d<4;d++)
					if(a[i+dx[d]][j+dy[d]]&16)
						a[i][j]=a[i+dx[d]][j+dy[d]];
				if(a[i][j]=='.')
					cout<<"-1\n",exit(0);
			}
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
}