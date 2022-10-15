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

int n,ans1,ans2,a[10000],T,now;

char ch;

signed main()
{
    T=read();now=1;
    while (T--)
    {
    	n=read();
    	ans1=0,ans2=1;
    	for (int i=1;i<=n;i++) cin>>ch,a[i]=ch-'0';
    	for (int i=1;i<=n;i+=2)
    	  ans1|=a[i]&1;
    	for (int i=2;i<=n;i+=2)
    	  ans2&=a[i]&1;
    	if (n&1)
    	{
    		if (ans1) writeln(1);
    		else writeln(2);
    	} else
    	{
    		if (ans2) writeln(1); else
    		writeln(2);
    	}
    }
}
/*
9602
*/