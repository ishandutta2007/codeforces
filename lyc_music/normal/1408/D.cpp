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

int n,m,a[2005],b[2005],c[2005],d[2005],f[2000005],ans;

signed main()
{
	n=read(),m=read();ans=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
	}
	for (int i=1;i<=m;i++)
	{
		c[i]=read(),d[i]=read();
	}
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	  {
	  	if (c[j]>=a[i]) f[c[j]-a[i]]=max(f[c[j]-a[i]],d[j]-b[i]+1);
	  }
	for (int i=2000000;i>=0;i--) f[i]=max(f[i],f[i+1]);
	for (int i=0;i<=2000000;i++) ans=min(ans,i+f[i]);
	writeln(ans);
}