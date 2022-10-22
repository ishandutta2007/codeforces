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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
int T,t,x0,x1,x2,yy0,y11,y2,ans;
signed main()
{
    T=read();
    while (T--)
    {
    	x0=read();
    	x1=read();
    	x2=read();
    	yy0=read();
    	y11=read();
    	y2=read();
		ans=0;
    	ans+=min(y11,x2)*2,t=min(y11,x2),y11-=t,x2-=t;
		ans+=min(y2,x2)*0,t=min(y2,x2),y2-=t,x2-=t;
		ans+=min(y2,x0)*0,t=min(y2,x0),y2-=t,x0-=t;
		ans+=min(y11,x1)*0,t=min(y11,x1),y11-=t,x1-=t;
		ans+=min(y11,x0)*0,t=min(y11,x0),y11-=t,x0-=t;
		ans+=min(yy0,x1)*0,t=min(yy0,x1),yy0-=t,x1-=t;
		ans+=min(x1,y2)*-2,t=min(x1,y2),x1-=t,y2-=t;
		cout<<ans<<endl;
	}
}