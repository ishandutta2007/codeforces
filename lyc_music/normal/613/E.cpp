//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

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

const long long vs=26;
const int N=4e3+7,p=1e9+7;
int n,m,h[N],t[2][N],f[2][N],dp[N][N][2][2];
char s[2][N],q[N];long long ans,w[N];

inline int gethsha(int l,int r)
{
	return ((t[0][r]-t[0][l-1]*w[r-l+1])%p+p)%p;
}
inline int gethshb(int l,int r)
{
	return ((t[1][r]-t[1][l-1]*w[r-l+1])%p+p)%p;
}
inline int gethshc(int l,int r)
{
	return ((f[0][l]-f[0][r+1]*w[r-l+1])%p+p)%p;
}
inline int gethshd(int l,int r)
{
	return ((f[1][l]-f[1][r+1]*w[r-l+1])%p+p)%p;
}
inline int gethshh(int l,int r)
{
	return ((h[r]-h[l-1]*w[r-l+1])%p+p)%p;
}
signed main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,q+1),n=strlen(s[0]+1),m=strlen(q+1),w[0]=1; bool fl=false;
	if(m==1)
	{
		for(int i=1;i<=n;i++) if(s[0][i]==q[1]) ans++;
		for(int i=1;i<=n;i++) if(s[1][i]==q[1]) ans++;
		writeln(ans);
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++) if(s[0][i]==q[1]&&s[1][i]==q[2]) ans++;
		for(int i=1;i<=n;i++) if(s[1][i]==q[1]&&s[0][i]==q[2]) ans++;
		for(int i=1;i<n;i++) if(s[0][i]==q[1]&&s[0][i+1]==q[2]) ans++;
		for(int i=n;i>1;i--) if(s[0][i]==q[1]&&s[0][i-1]==q[2]) ans++;
		for(int i=1;i<n;i++) if(s[1][i]==q[1]&&s[1][i+1]==q[2]) ans++;
		for(int i=n;i>1;i--) if(s[1][i]==q[1]&&s[1][i-1]==q[2]) ans++;
		cout<<ans<<endl; return 0;
	}
	if(m>n*2) {puts("0"); return 0;} for(int i=1;i<=2*n;i++) w[i]=w[i-1]*vs%p;
	for(int i=1;i<=m;i++) if(q[i]!=q[m-i+1]) fl=1;
	for(int z=0;z<=1;z++)
	{
		for(int i=1;i<=n;i++) t[z][i]=(t[z][i-1]*vs+(s[z][i]-'a'))%p;
		for(int i=n;i>=1;i--) f[z][i]=(f[z][i+1]*vs+(s[z][i]-'a'))%p;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++) h[i]=(h[i-1]*vs+q[i]-'a')%p;
	for(int i=1;i<=n;i++)
		for(int x=2;x<=min(i,m/2);x++)
		{
			if((gethshc(i-x+1,i)*w[x]+gethshb(i-x+1,i))%p==gethshh(1,2*x)) dp[i][2*x][1][1]=1;
			if((gethshd(i-x+1,i)*w[x]+gethsha(i-x+1,i))%p==gethshh(1,2*x)) dp[i][2*x][0][1]=1;
			if(x==m/2) ans=(ans-dp[i][2*x][1][1]-dp[i][2*x][0][1])%p;
		}
	for(int i=1;i<=n;i++){
		if(q[1]==s[0][i]) dp[i][1][0][0]++; if(q[1]==s[1][i]) dp[i][1][1][0]++;
	}
	for(int i=1;i<=n;i++)
		for(int x=1;x<=m;x++)
		{
			if(s[0][i]==q[x+1]) dp[i][x+1][0][1]=(dp[i][x+1][0][1]+dp[i][x][1][0])%p;
			if(s[1][i]==q[x+1]) dp[i][x+1][1][1]=(dp[i][x+1][1][1]+dp[i][x][0][0])%p;				
			if(s[0][i+1]==q[x+1]) dp[i+1][x+1][0][0]=(dp[i+1][x+1][0][0]+(dp[i][x][0][0]+dp[i][x][0][1])%p)%p;
			if(s[1][i+1]==q[x+1]) dp[i+1][x+1][1][0]=(dp[i+1][x+1][1][0]+(dp[i][x][1][0]+dp[i][x][1][1])%p)%p;
		}
	for(int i=0;i<=n;i++) dp[i][0][0][0]=dp[i][0][1][0]=1;
	for(int i=0;i<=n;i++)
		for(int x=0;x<=m;x++)
		{
			if((m-x)&1||m-x==2) continue; if(i+(m-x)/2>n) continue; int z=m-x;
			if(x==m)
			{
				ans=(ans+dp[i][x][0][0]+dp[i][x][0][1]+dp[i][x][1][0]+dp[i][x][1][1])%p; continue;
			}
			if(z==2||x==0) continue; 
			if((gethshd(i+1,i+z/2)+gethsha(i+1,i+z/2)*w[z/2])%p==gethshh(m-z+1,m)) ans=(ans+dp[i][x][0][0]+dp[i][x][0][1])%p;
			if((gethshc(i+1,i+z/2)+gethshb(i+1,i+z/2)*w[z/2])%p==gethshh(m-z+1,m)) ans=(ans+dp[i][x][1][0]+dp[i][x][1][1])%p;
		}
	memset(dp,0,sizeof(dp)); 
	for(int i=1;i<=m/2;i++) swap(q[i],q[m-i+1]);
	for(int i=1;i<=m;i++) h[i]=(h[i-1]*vs+q[i]-'a')%p;
	for(int i=1;i<=n;i++)
		for(int x=2;x<=min(i,m/2);x++)
		{
			if((gethshc(i-x+1,i)*w[x]+gethshb(i-x+1,i))%p==gethshh(1,2*x)) dp[i][2*x][1][1]=1;
			if((gethshd(i-x+1,i)*w[x]+gethsha(i-x+1,i))%p==gethshh(1,2*x)) dp[i][2*x][0][1]=1;
		}
	for(int i=1;i<=n;i++)
	{
		if(q[1]==s[0][i]) dp[i][1][0][0]++; if(q[1]==s[1][i]) dp[i][1][1][0]++;
	}
	for(int i=1;i<=n;i++)
		for(int x=1;x<=m;x++)
		{
			if(s[0][i]==q[x+1]) dp[i][x+1][0][1]=(dp[i][x+1][0][1]+dp[i][x][1][0])%p;
			if(s[1][i]==q[x+1]) dp[i][x+1][1][1]=(dp[i][x+1][1][1]+dp[i][x][0][0])%p;
			if(s[0][i+1]==q[x+1]) dp[i+1][x+1][0][0]=(dp[i+1][x+1][0][0]+(dp[i][x][0][0]+dp[i][x][0][1])%p)%p;
			if(s[1][i+1]==q[x+1]) dp[i+1][x+1][1][0]=(dp[i+1][x+1][1][0]+(dp[i][x][1][0]+dp[i][x][1][1])%p)%p;
	}
	for(int i=0;i<=n;i++) dp[i][0][0][0]=dp[i][0][1][0]=1;
	for(int i=0;i<=n;i++)
		for(int x=0;x<=m;x++)
		{
			if((m-x)&1||m-x==2) continue; if(i+(m-x)/2>n) continue; int z=m-x;
			if(x==m)
			{
				ans=(ans+dp[i][x][0][0]+dp[i][x][0][1]+dp[i][x][1][0]+dp[i][x][1][1])%p; continue;
			}
			if((gethshd(i+1,i+z/2)+gethsha(i+1,i+z/2)*w[z/2])%p==gethshh(m-z+1,m)) ans=(ans+dp[i][x][0][0]+dp[i][x][0][1])%p;
			if((gethshc(i+1,i+z/2)+gethshb(i+1,i+z/2)*w[z/2])%p==gethshh(m-z+1,m)) ans=(ans+dp[i][x][1][0]+dp[i][x][1][1])%p;
		}
	writeln(ans);
}