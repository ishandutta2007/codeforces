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

int T,n,mx,ans[10005],a[10005],b[10005],tp;

int gcd(int x,int y)
{
	if (!y)return x;
	return gcd(y,x%y);
}

signed main()
{
	T=read();
	while (T--)
	{
		n=read();a[0]=1;mx=0;
		for (int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]),b[i]=0;
		sort(a+1,a+n+1);
        mx=a[n];
        writesp(a[n]),b[n]=1;
        for(int i=2;i<=n;i++){
            int mxd=0,ans;
            for(int j=n-1;j>=1;j--)
			    if(!b[j]&&gcd(a[j],mx)>mxd) 
				    mxd=gcd(a[j],mx),ans=j;
            b[ans]=1;
			writesp(a[ans]),mx=gcd(mx,a[ans]);
        }
        puts("");
	}
}