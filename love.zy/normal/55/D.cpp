#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
int g[2521],cnt;
int lcm[2521][10];
char d[20];
LL dp[20][48][2520];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
LL dfs(int len, int id, int mod,bool bound)
{
	if (len == 0)return mod%id==0;
	if (!bound && ~dp[len][g[id]][mod])return dp[len][g[id]][mod];
	LL num = 0;
	int max = bound ? d[len] : 9;
	for (int i = 0; i <= max; i++)
		num+=dfs(len-1,lcm[id][i],(mod*10+i)%2520,bound&&i==max);
	if (!bound)dp[len][g[id]][mod] = num;
	return num;
}
LL solve(LL n)
{
	int bit = 0;
	for (; n; n /= 10)d[++bit] = n % 10;
	return dfs(bit,1,0,1);
}
int main()
{
	for(int i=1;i<=2520;i++){
		if(2520%i==0)g[i]=cnt++;
	}
	for(int i=1;i<=2520;i++){
		lcm[i][0]=i;
		for(int j=1;j<=9;j++)
			lcm[i][j]=i*j/gcd(i,j);
	}
	int test;
	LL l, r;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&test);
	while(test--){
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r)-solve(l-1));
	}
}