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

int T,n,k,l,p,bl,now,t,la;

signed main()
{
	T=read();
	while (T--)
	{
		bl=1;
		la=0;
		n=read(),k=read(),l=read();
		for(int i=1;i<=n;i++)
		{
			now=read();
			if (now>l) bl=0;
			else if(now+k<=l) la=0;
			else if(la<k)la=max(la+1,k+now-l);
			else if(k+l-now-1<la) bl=0;
				else la++;
		}
		puts(bl?"Yes":"No");
	}
}