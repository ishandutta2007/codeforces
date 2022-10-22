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

int T,x,y,a,b,k,tt,xx,yy,aa,bb,kk;
signed main()
{
    T=read();
    while (T--)
    {
    	x=read(),y=read(),a=read(),b=read(),k=read();
    	xx=x,yy=y,aa=a,bb=b,kk=k;
    	tt=min(xx-aa,k);
    	xx-=tt;
    	k-=tt;
    	tt=min(yy-bb,k);
    	yy-=tt;
    	k-=tt;
    	k=kk;
		tt=min(y-b,k);
    	y-=tt;
    	k-=tt;
    	tt=min(x-a,k);
    	x-=tt;
    	k-=tt;
    	writeln(min(xx*yy,x*y));
    	//cout<<xx<<" "<<yy<<" "<<x<<" "<<y<<endl;
    }
}