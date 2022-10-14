#include<bits/stdc++.h>
#define ANS(x,y) {if(x){cout<<y<<"\n";goto end;}}
using namespace std;
int const N=233;
int t,n,m,s[N][N];
char a[N][N];
int ck(int a,int b,int c,int d){
	return s[c][d]-s[c][b-1]-s[a-1][d]+s[a-1][b-1]==(c-a+1)*(d-b+1);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j],
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='A');
		ANS(s[n][m]==n*m,0)
		ANS(!s[n][m],"MORTAL")
		ANS(ck(1,1,1,m)||ck(1,1,n,1)||ck(1,m,n,m)||ck(n,1,n,m),1)
		ANS(ck(1,1,1,1)||ck(n,1,n,1)||ck(1,m,1,m)||ck(n,m,n,m),2)
		for(int i=1;i<=n;i++)
			ANS(ck(i,1,i,m),2)
		for(int i=1;i<=m;i++)
			ANS(ck(1,i,n,i),2)
		for(int i=1;i<=n;i++)
			ANS(ck(i,1,i,1)||ck(i,m,i,m),3)
		for(int i=1;i<=m;i++)
			ANS(ck(1,i,1,i)||ck(n,i,n,i),3)
		ANS(1,4) 
end:	;	
	}
}