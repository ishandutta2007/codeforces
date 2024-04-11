#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int n,m;
int c[N][N];
vector<vector<int>> res;

bool ne(int a,int b){
	if(!a||!b)return 0;
	return a!=b;
}

void check(int i,int j){
	if(i+1>n||j+1>m||i<1||j<1)return;
	int A=c[i][j],B=c[i][j+1],C=c[i+1][j],D=c[i+1][j+1];
	if(A+B+C+D==0)return ;
	int col=A;
	if(B)col=B;if(C)col=C;if(D)col=D; 
	if(ne(A,B))return ;
	if(ne(A,C))return ;
	if(ne(A,D))return ;
	if(ne(B,C))return ;
	if(ne(B,D))return ;
	if(ne(C,D))return ;
	res.push_back({i,j,col});
	c[i][j]=c[i+1][j]=c[i+1][j+1]=c[i][j+1]=0;
	for(int x=-1;x<=1;x++)
		for(int y=-1;y<=1;y++)
			check(i+x,j+y); 
}

void solve(){
	res.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			check(i,j); 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j])cout<<-1,exit(0); 
	cout<<res.size()<<'\n';
	reverse(res.begin(),res.end());
	for(auto x:res){
		for(auto y:x)cout<<y<<' ';
		cout<<'\n';
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}