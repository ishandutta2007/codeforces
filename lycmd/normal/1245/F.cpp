#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=35;
int t,l,r,a,b,f[N][2][2];
int dfs(int x,int fx,int fy){
	if(!~x)return 1; 
	int&res=f[x][fx][fy],f1=fx||a>>x&1,f2=fy||b>>x&1;
	if(~res)return res;
	res=dfs(x-1,f1,f2);
	if(f1)res+=dfs(x-1,fx,f2);
	if(f2)res+=dfs(x-1,f1,fy);
	return res;
}
int solve(int l,int r){
	if(l<0||r<0)return 0;
	a=l,b=r,memset(f,-1,sizeof f);
	return dfs(30,0,0);
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>l>>r;
		cout<<solve(r,r)+solve(l-1,l-1)-2*solve(l-1,r)<<"\n";
	}
}