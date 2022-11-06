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

int T,x,y,x1,y1;

signed main()
{
	T=read();
	while (T--)
	{
		x=read(),y=read(),x1=read(),y1=read();
		writeln(min(abs(x1-x)+((x1==x)?0:2)+abs(y1-y),abs(x1-x)+((y1==y)?0:2)+abs(y1-y)));
	}
}