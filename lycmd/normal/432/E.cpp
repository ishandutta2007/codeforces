#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,m;
char a[N][N];
int mex(int x,int y){
	if(a[x][y])return a[x][y];
	for(int i=65;;i++)
		if(a[x-1][y]^i&&a[x+1][y]^i&&a[x][y-1]^i&&a[x][y+1]^i)
			return i;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j]){
				int w=0,c=mex(i,j);
				while(mex(i,j+w)==c&&i+w<=n&&j+w<=m)w++;
				for(int x=i;x<i+w;x++)
					for(int y=j;y<j+w;y++)
						a[x][y]=c;
			}
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
}