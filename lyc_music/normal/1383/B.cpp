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

int T,n,bl,bl1,a[100005],b[35],k,sum,sum1;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();sum=0;sum1=0;
		for (int i=0;i<=30;i++) b[i]=0;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();sum^=a[i];
			k=0;
			while (a[i]>0) 
			{
				if (a[i]&1) b[k]++;
				a[i]>>=1;
				k++;
			}
		}
		if (!sum) puts("DRAW");
		else
		{
		for (int i=30;i>=0;i--)
		  if (b[i]&1) 
		  {
		  	sum1=b[i];
		  	break;
		  }
		if (sum1%4==3&&(n-sum1)%2==0) puts("LOSE");
		else puts("WIN");}
	}
}