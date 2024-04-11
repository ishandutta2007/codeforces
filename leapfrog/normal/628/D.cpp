#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
// int debug[2005];
const int P=1000000007;int m,d,cnt,a[2005],dp[2005][2005][2][2][2];string l,r;
// inline void outdebug() {for(int i=1;i<=cnt;i++) printf("%d%c",debug[i],i==cnt?'\n':' ');}
inline char chk(string s)
{
	int r=0;
	for(int i=0;i<(int)s.size();i++) if((i&1)^(s[i]==d+'0')) return 0;else r=(10*r+s[i]-'0')%m;
	return !r;
}
inline int dfs(int x,int w,int g,int lim,int zer)
{
	// if(x==cnt+1&&w==0) exit(0);
	int &r=dp[x][w][g][lim][zer],ed;if(r!=-1) return r;else r=0;
	if(x==cnt+1) {if(w==0) return r=1;else return r=0;}else ed=lim?a[x]:9;
	// printf("and now, the g is %d and the w is %d ; zero is %d\n",g,w,zer);
	for(int i=0;i<=ed;i++)
		if(g^(i==d))
		{
			// printf("we choose %d at %d\n",i,x);
			// debug[x]=i;
			if(zer&&!i) (r+=dfs(x+1,(w*10+i)%m,1,lim&&i==ed,1))%=P;
			else (r+=dfs(x+1,(w*10+i)%m,g^1,lim&&i==ed,0))%=P;
		}
	return r%P;
}
inline int solve(string s)
{
	memset(dp,-1,sizeof(dp)),cnt=s.size();
	for(int i=1;i<=cnt;i++) a[i]=s[i-1]-'0';
	return dfs(1,0,1,1,1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>m>>d>>l>>r,cout<<((solve(r)-solve(l)+chk(l))%P+P)%P<<endl;
	return 0;
}