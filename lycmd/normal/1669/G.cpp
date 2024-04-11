#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=55;
int t,n,m;
char a[N][N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int flg=0;
			for(int x=1;x<n;x++)
				for(int y=1;y<=m;y++)
					if(a[x][y]=='*'&&a[x+1][y]=='.')
						swap(a[x][y],a[x+1][y]),flg=1;
			if(!flg)break;
		}
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=m;j++)
				cout<<a[i][j];
	}
	return 0;
}