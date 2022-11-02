#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,T,f[65][2][2][2];
int dfs(int x,int a,int b,int c){
	if(x==63)return (!a)&&(b^c);
	int &o=f[x][a][b][c];
	if(~o)return o;o=0;
	for(int i=0;i<2;i++){
		int u=i+b+((n>>x)&1);
		o+=dfs(x+1,(m>>x&1)?(i?a:0):(i?1:a),u/2,c^(u&1)^i);
	}return o;
}
signed main(){
	cin>>T;
	while(T--){
		memset(f,-1,sizeof f);cin>>n>>m;m--;
		cout<<dfs(0,0,0,0)<<endl;
	}
}