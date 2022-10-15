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
char ch[1005][1005];
int T,n,m,b[1005][1005],sum;
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		    cin>>ch[i][j];
		sum=0;
		for (int i=1;i<m;i++) if (ch[n][i]!='R') sum++;
		for (int i=1;i<n;i++) if (ch[i][m]!='D') sum++;
		writeln(sum);
	}
}