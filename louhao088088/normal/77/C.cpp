#include<bits/stdc++.h>
#define For(pos) for(int k=First[pos];k;k=Next[k])
#define int long long 
using namespace std;
const int Maxn=1e5+5;
inline int R()
{
	char c;int sign=1,res=0;
	while((c=getchar())>'9'||c<'0') if(c=='-') sign=-1;res+=c-'0';
	while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
	return res*sign;	
}
int First[Maxn],to[Maxn*2],Next[Maxn*2],WE[Maxn],n,cnt,dp[Maxn];
inline void add(int z,int y)
{
	Next[++cnt]=First[z];
	First[z]=cnt;
	to[cnt]=y; 
} 
int ans=0,RT;
void dfs(int pos,int father)// 
{
	//M=min(WE[pos],M);
	//ans+=M;
//	set<int>S;
	if(WE[pos]==1&&pos!=RT) 
	{
		//ans++;
		WE[pos]--;
		dp[pos]=1;
		return;
	}
	priority_queue<int>S;
	int res=1,res1=0,P,num=0,sum=0;;
	For(pos)
	{
		res=2;
		if(to[k]==father)continue;
		dfs(to[k],pos);
		S.push(dp[to[k]]);
		sum+=dp[to[k]];
		num++;
		if(WE[to[k]]) res1+=WE[to[k]];
		//if(WE[to[k]]>2)res1+=min(WE[to[k]]-P,P-2);//toWE[to[k]]-pos 
	}
	//if(pos==RT) res=1;
	if(pos!=RT)
	{
		WE[pos]--;
		dp[pos]++;
	}
	if(num>WE[pos])
	{
		while(WE[pos]>0)
		{
			dp[pos]+=S.top();
			dp[pos]++;
			S.pop();
			WE[pos]--;
		}
	}
	else 
	{
		dp[pos]+=sum;
		dp[pos]+=num;
		WE[pos]-=num;
		dp[pos]+=2*min(WE[pos],res1);
		WE[pos]-=min(WE[pos],res1);
	}
	//ans+=min(res+res1,WE[pos]);
	return; 
//	if(res>WE[pos]) res=WE[pos];
//	return res;
}
signed main()
{
	n=R();
	for(int i=1;i<=n;i++) WE[i]=R();
	int x,y;
	for(int i=1;i<n;i++)
	{
		x=R();y=R();
		add(x,y);
		add(y,x); 
	}
	RT=R();
	//WE[x]++;
	//for(int i=1;i<=n;i++) WE[i]/=2;
	dfs(RT,0);
	printf("%lld\n",dp[RT]);
}