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

int n,a[500000],ans1,ans2;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
	    ans1+=a[i]/2;
	    ans2+=a[i]/2;
	    if(a[i]&1)
	    {
	        if(i&1) ans1++;
	        else ans2++;
	    } 
	}
	writeln(min(ans1,ans2));
}