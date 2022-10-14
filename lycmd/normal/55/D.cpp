#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=2520,N=3010,M=65;
int tot,t,l,r,a[N],d[M],f[M][N][M];
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int dfs(int l,int y,int m,int op){
	if(!l)return y%m==0;
	if(!op&&~f[l][y][a[m]])
	    return f[l][y][a[m]];
	int ans=0;
	for(int i=0;i<=(op?d[l]:9);i++)
		ans+=dfs(l-1,(y*10+i)%MOD,i?m/gcd(m,i)*i:m,
		    op&&i==(op?d[l]:9));
	if(!op)f[l][y][a[m]]=ans;
	return ans;
}
int solve(int x){
	int tot=0;
	while(x)d[++tot]=x%10,x/=10;
	return dfs(tot,0,1,1);
}
signed main(){
    ios::sync_with_stdio(0);
	memset(f,-1,sizeof f);
	for(int i=1;i<=MOD;i++)
	    if(MOD%i==0)a[i]=++t;
	for(cin>>t;t--;)
	    cin>>l>>r,cout<<solve(r)-solve(l-1)<<"\n";
}