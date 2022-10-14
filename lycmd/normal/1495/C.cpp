#include<bits/stdc++.h>
using namespace std;
int const N=666;
int t,n,m;
char mp[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		memset(mp,0,sizeof mp);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		for(int i=1;i<=n;i+=3)
			for(int j=1;j<=m;j++)
				mp[i][j]='X';
		for(int i=2;i<=n;i+=3){
			int flg=1;
			for(int j=1;j<=m&&flg;j++)
				if(mp[i][j]=='X'&&flg)
					mp[i+1][j]='X',flg=0;
				else if(mp[i+1][j]=='X'&&flg)
					mp[i][j]='X',flg=0;
			if(flg)mp[i][1]=mp[i+1][1]='X';
		}
		if(n%3==0){
			for(int j=1;j<=m;j++)
				if(mp[n][j]=='X')
					mp[n-1][j]='X';
		}
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=m;j++)
				cout<<mp[i][j];
	}
}
//written by 2_3_3