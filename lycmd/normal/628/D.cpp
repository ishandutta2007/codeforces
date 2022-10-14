#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,MOD=1000000007;
int m,k,tot,d[N],f[N][N];
string l,r;
int dfs(int x,int s,int l){
	if(!x)
		return !s;
	if(!l&&~f[x][s])
		return f[x][s];
	int res=0;
	for(int i=0;i<=(l?d[x]:9);i++)
		if(((tot-x)&1)^(i!=k))
			res=(res+dfs(x-1,(s*10+i)%m,l&&i==(l?d[x]:9)))%MOD;
	return l?res:f[x][s]=res;
}
int solve(const string&x){
	tot=x.size();
	for(int i=0;i<tot;i++)
		d[tot-i]=x[i]-48;
	return dfs(tot,0,1);
}
int check(string x){
	int s=0;
	for(int i=0;i<x.size();i++)
		if((i&1)^(x[i]!=k+48))
			s=(s*10+x[i]-48)%m;
		else
			return 0;
	return!s;
}
signed main(){
	memset(f,-1,sizeof f);
	cin>>m>>k>>l>>r;
	cout<<(solve(r)-solve(l)+check(l)+MOD)%MOD<<"\n";
}