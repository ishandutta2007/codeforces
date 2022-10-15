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

int n,x,y,z,x1,y1,z1;

signed main()
{
	n=read();
	x=read(),y=read(),z=read(),x1=read(),y1=read(),z1=read();
	cout<<n-min(x,n-y1)-min(y,n-z1)-min(z,n-x1)<<" "<<min(x,y1)+min(y,z1)+min(z,x1);
}