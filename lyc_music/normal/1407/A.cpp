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

int T,n,l1,r1,a[100005];

signed main()
{
	T=read();
	while (T--)
	{
		n=read();l1=r1=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i]==0) l1++; else r1++;
		}
		if (l1>=n/2)
		{
			writeln(l1);
			for (int i=1;i<=l1;i++) writesp(0);
		} else
		{
			writeln(r1-(r1&1));
			for (int i=1;i<=r1-(r1&1);i++) writesp(1);
		}
		puts("");
	}
}