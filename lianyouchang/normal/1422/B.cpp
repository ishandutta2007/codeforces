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

int T,n,m,ans,a[1005][1005],p[5],tot;

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			  a[i][j]=read();
		}
		for (int i=1;i<=(n/2)+(n&1);i++)
		  for (int j=1;j<=(m/2)+(m&1);j++)
		  {
		  	tot=0;
		    tot++,p[tot]=a[i][j];
			if (n-i+1!=i) tot++,p[tot]=a[n-i+1][j];
			if (m-j+1!=j) tot++,p[tot]=a[i][m-j+1];
			if (n-i+1!=i&&m-j+1!=j) tot++,p[tot]=a[n-i+1][m-j+1];
		  	sort(p+1,p+tot+1);
		  	for (int j=1;j<=tot/2;j++) ans+=p[j+tot/2]-p[j];
		  }
		writeln(ans);
	}	
}