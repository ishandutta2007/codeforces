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

int T,n,T1,a[100005],ans[100005],tp;

signed main()
{
	T1=read();
	while (T1--)
	{
		n=read(),T=read();tp=0;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) if ((double)a[i]<(double)T/2) ans[i]=0; else if ((double)a[i]>(double)T/2)ans[i]=1; else ans[i]=tp,tp=1^tp;
		for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}