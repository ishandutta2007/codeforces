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

int T,n,ans,bl,bl1;

char a[N],ch;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();bl=bl1=1;ch='-';
		for (int i=1;i<=n;i++) {a[i]=getchar();if (a[i]!='-') ch=a[i];}
		for (int i=1;i<=n;i++) 
		{
			bl&=a[i]==ch||a[i]=='-';
		}
		if (bl) 
		{
			writeln(n);
			continue;
		}
		ans=0;a[n+1]=a[1];
		for (int i=1;i<=n;i++) 
		{
			if (a[i]=='-'||a[i+1]=='-') ans++;
		}
		writeln(ans);
	}
}