#include<bits/stdc++.h>
using namespace std;
int const N=333;
int t,n,cnt,flg;
char a[N][N],b[N][N];
void check(string op){
	if(flg)return;
	int t=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=a[i][j]=='.'||op[(i+j)%3]=='.'?a[i][j]:op[(i+j)%3],
			t+=a[i][j]!=b[i][j];
	if(t<=cnt/3){
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=n;j++)
				cout<<b[i][j];
		flg=1;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cnt=flg=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j],cnt+=a[i][j]!='.';
		check(".OX");check(".XO");
		check("O.X");check("OX.");
		check("X.O");check("XO.");
	}
}