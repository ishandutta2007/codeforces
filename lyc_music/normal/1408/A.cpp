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

int T,n,a[1000],b[1000],c[1000],p[1000];

signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) b[i]=read();
		for (int i=1;i<=n;i++) c[i]=read();
		p[n-1]=a[n-1];
		for (int i=n-2;i>=1;i--)
		{
			if (a[i]!=p[i%n+1]) p[i]=a[i]; else
			if (b[i]!=p[i%n+1]) p[i]=b[i]; else
			if (c[i]!=p[i%n+1]) p[i]=c[i];
		}for (int i=n;i>=n;i--)
		{
			if (a[i]!=p[i%n+1]&&a[i]!=p[n-1]) p[i]=a[i]; else
			if (b[i]!=p[i%n+1]&&b[i]!=p[n-1]) p[i]=b[i]; else
			if (c[i]!=p[i%n+1]&&c[i]!=p[n-1]) p[i]=c[i];
		}
		for (int i=1;i<=n;i++) writesp(p[i]);
		puts("");
	}
}