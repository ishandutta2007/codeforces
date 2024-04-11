#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int n,m,a[8][1000005],ans,sxy1,sxy2,tans,dp[1000005][8];
char ch;
int cha(int l,int x)
{
	return (((x>>0)&1)^a[1][l])+(((x>>1)&1)^a[2][l])+(((x>>2)&1)^a[3][l]);
}
bool check(int x,int y)
{
	if((x>>2&1)^(x>>1&1)^(y>>2&1)^(y>>1&1)==0)return 0;
	if((x>>0&1)^(x>>1&1)^(y>>0&1)^(y>>1&1)==0)return 0;
	return 1;
}
signed main()
{
	ans=INT_MAX;
	n=read();
	m=read();
	if (n>3&&m>3) writeln(-1);
	else
	{for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++) 
	  {cin>>ch;
	  if (n>m) 
	    a[j][i]=ch-'0'; else a[i][j]=ch-'0';}
	if (n>m) swap(n,m);
	if (n<=1)
	{
		writeln(0);
	} else
	if (n<=2)
	{
		sxy1=0,sxy2=0;
		tans=a[1][2]^a[2][2];
		if (a[1][1]^a[1][2]^a[2][1]^a[2][2]==0) sxy1++,tans^=1;
		for (int i=3;i<=m;i++)
		  if (tans^a[1][i]^a[2][i]==0)
		  {
		  	sxy1++,tans=a[1][i]^a[2][i]^1;
		  } else tans=a[1][i]^a[2][i];
    		tans=a[1][2]^a[2][2];
		if (a[1][1]^a[1][2]^a[2][1]^a[2][2]==0) sxy2++;
		for (int i=3;i<=m;i++)
		  if (tans^a[1][i]^a[2][i]==0)
		  {
		  	sxy2++,tans=a[1][i]^a[2][i]^1;
		  } else tans=a[1][i]^a[2][i];
		writeln(min(sxy1,sxy2));
	} else
	if (n<=3)
	{
		for (int i=0;i<=7;i++) dp[1][i]=cha(1,i);
		for (int i=2;i<=m;i++)
		  for (int j=0;j<=7;j++)
		  {
		  	dp[i][j]=99999999999;
		  	for (int k=0;k<=7;k++)
		  	  if (check(j,k))
		  	  {
		  	  	dp[i][j]=min(dp[i][j],dp[i-1][k]+cha(i,j));
		  	  }
		  	if (i==m) ans=min(ans,dp[i][j]);
		  }
		writeln(ans);
	}}
}