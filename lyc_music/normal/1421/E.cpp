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

int n,a[200005],f[200005][3][3][3];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) 
		a[i]=read();
	memset(f,0xc0,sizeof(f));
	if (n==1) return writeln(a[1]),0;
	f[0][0][0][1]=0;
	for (int i=0;i<n;i++)
	  for (int j=0;j<=2;j++)
	    for (int k=0;k<2;k++)
		  	{
	        	f[i+1][(j+2)%3][0][0]=max(f[i+1][(j+2)%3][0][0],f[i][j][k][0]-a[i+1]);
                f[i+1][(j+1)%3][1][0]=max(f[i+1][(j+1)%3][1][0],f[i][j][k][0]+a[i+1]);
                f[i+1][(j+2)%3][0][((i&1)&&k==1)]=max(f[i+1][(j+2)%3][0][((i&1)&&k==1)],f[i][j][k][1]-a[i+1]);
                f[i+1][(j+1)%3][1][(!(i&1)&&k==0)]=max(f[i+1][(j+1)%3][1][(!(i&1)&&k==0)],f[i][j][k][1]+a[i+1]);
			}
	writeln(max(f[n][1][0][0],f[n][1][1][0]));
	return 0;
}