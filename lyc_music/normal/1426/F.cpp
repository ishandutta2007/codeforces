//QwQcOrZ yyds!!!
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

int n,f[200005][4],p3,mod=1e9+7,ppp=333333336;
char ch[200005];

signed main()
{
	n=read();p3=1;
	for (int i=1;i<=n;i++)
	{
		cin>>ch[i];
		if (ch[i]=='?') (p3*=3)%=mod;
	}
	for (int i=1;i<=n;i++)
	{
		f[i][1]=f[i-1][1],f[i][2]=f[i-1][2],f[i][3]=f[i-1][3];
		if (ch[i]=='a')
		{
			f[i][1]=(f[i][1]+p3)%mod;
		}
		if(ch[i]=='b')
		{
			f[i][2]=(f[i][2]+f[i-1][1])%mod;
		}
		if(ch[i]=='c')
		{
			f[i][3]=(f[i][3]+f[i-1][2])%mod;
		}
		if(ch[i]=='?')
		{
			f[i][1]=(f[i][1]+ppp%mod*p3)%mod;
			f[i][2]=(f[i][2]+f[i-1][1]*ppp%mod)%mod;
			f[i][3]=(f[i][3]+f[i-1][2]*ppp%mod)%mod;
		}
	}
	writeln(f[n][3]);
}