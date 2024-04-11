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

int n,pos,l,r,ans;

signed main()
{
	n=read(),pos=read(),l=read(),r=read();
	if (l==1&&r==n) writeln(0);else
	if (l==1) writeln(abs(r-pos)+1);
	else if (r==n) writeln(abs(pos-l)+1);
	else writeln(min(abs(pos-l)+abs(r-l),abs(pos-r)+abs(r-l))+2);
}