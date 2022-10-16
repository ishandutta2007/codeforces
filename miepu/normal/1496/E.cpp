#include<bits/stdc++.h>
#define int long long
const int N=505;
using namespace std;

int n,m;
int col[N][N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			col[i][j+1]=s[j]=='X';
		}
	}
	int t=n%3==0?2:1;
	for(int i=t;i<=n;i+=3)
		for(int j=1;j<=m;j++)
			col[i][j]=1;
	for(int i=t;i+3<=n;i+=3){
		int t=col[i+1][2]||col[i+2][2];
		col[i+1][t+1]=col[i+2][t+1]=1;
	}
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=m;j++)
			cout<<(col[i][j]?'X':'.');
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}