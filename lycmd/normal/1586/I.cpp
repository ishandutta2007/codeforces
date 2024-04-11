#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,flg[N];
char mp[N][N];
inline void update(int x,int p){
	if(flg[x]!=-1&&flg[x]!=p)cout<<"NONE\n",exit(0);
	flg[x]=p;
}
inline void print(int x,int p){
	cout<<(flg[x]^p?"S":"G");
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	if(n&1)cout<<"NONE\n",exit(0);
	memset(flg,-1,sizeof flg);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]!='.'){
				int op=mp[i][j]=='S';
				if(i==1&&j==1||i==n&&j==n)update(1,op);
				else if(i==n&&j==1||i==1&&j==n)update(n>>1,op);
				else if(i<j&&(j-i&1))update(j-i+1>>1,op^(i-1&1));
				else if(i>j&&(i-j&1))update(i-j+1>>1,op^(j-1&1));
				else if(i+j<=n&&!(i+j&1))update(i+j>>1,op^(n-j+1&1));
				else if(i+j>n&&!(i+j&1))update(n*2-i-j+2>>1,op^(n-i&1));
			}
	for(int i=1;i<=n>>1;i++)	
		if(flg[i]<0)cout<<"MULTIPLE\n",exit(0);
	cout<<"UNIQUE\n";
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			if(mp[i][j]=='.'){
				if(i==1&&j==1||i==n&&j==n)print(1,0);
				else if(i==n&&j==1||i==1&&j==n)print(n>>1,0);
				else if(i<j&&(j-i&1))print(j-i+1>>1,i-1&1);
				else if(i>j&&(i-j&1))print(i-j+1>>1,j-1&1);
				else if(i+j<=n&&!(i+j&1))print(i+j>>1,n-j+1&1);
				else if(i+j>n&&!(i+j&1))print(n*2-i-j+2>>1,n-i&1);
			}else cout<<mp[i][j];
	return 0;
}