//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 2000005

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

int T,n,p,a[N],k,l1,l2,mod1=1e9+7,mod2=1024;

int qpower(int x,int y,int mo)
{
	int res=1;
	while (y>0)
	{
		if (y&1) (res*=x%mo)%=mo;
		(x*=x%mo)%=mo;
		y>>=1;
	}
	return res;
}

signed main()
{
	T=read();
	while (T--)
	{
		n=read(),p=read();
		for (int i=1;i<=n;i++) a[i]=read();
		if (p==1)
		{
			writeln(n&1);
			continue;
		}
		sort(a+1,a+n+1);
		l1=0,l2=0;
		for (int i=n;i>=1;i--)
		  if (!l1&&!l2)
		  {
		  	(l1+=(qpower(p,a[i],mod1)))%=mod1;
		  	(l2+=(qpower(p,a[i],mod2)))%=mod2;
		  } else
		  {
		  	(l1=l1-qpower(p,a[i],mod1)+mod1)%=mod1;
		  	(l2=l2-qpower(p,a[i],mod2)+mod2)%=mod2;
		  }
		writeln(l1);
	}
}