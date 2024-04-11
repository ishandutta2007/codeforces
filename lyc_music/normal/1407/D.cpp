//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 300005


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

int n,a[N],q[N],top,dp[N],k1,top1,q1[N];

signed main()
{
	n=read();memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for (int i=1;i<=n;i++) a[i]=read();
	top=top1=1;q[1]=q1[1]=1;
	for (int i=2;i<=n;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		while (top&&a[q[top]]>=a[i]) 
		{
			k1=a[q[top]];
			top--;
			if (a[i]!=k1&&top) dp[i]=min(dp[i],dp[q[top]]+1);
		}
		q[++top]=i;
		while (top1&&a[q1[top1]]<=a[i]) 
		{
			k1=a[q1[top1]];
			top1--;
			if (a[i]!=k1&&top1) dp[i]=min(dp[i],dp[q1[top1]]+1);
		}
		q1[++top1]=i;
	}
	top=0;
	writeln(dp[n]);
}