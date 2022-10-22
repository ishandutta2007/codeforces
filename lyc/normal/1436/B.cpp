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

int f[100005],T,n,a[105][105],tp;

signed main()
{
	f[1]=1;
	for (int i=2;i*i<=100000;i++)
		for (int j=2;j*i<=100000;j++)
		  f[i*j]=1;
	T=read();
	while (T--)
	{
		n=read();memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[i][i]=1;
		for (tp=1;tp<=100000;tp++)
		{
			if (!f[tp]) continue;
			if (!f[(n-1)*tp+1]) break;
		}
		for (int i=1;i<=n;i++) 
		  for (int j=1;j<=n;j++)
		    if (!a[i][j]) a[i][j]=tp;
		for (int i=1;i<=n;i++)
		{
		  for (int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		  puts("");
	}
}
}