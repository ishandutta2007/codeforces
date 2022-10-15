//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 100005

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

int n,a[N],Ans,ans[N],cnt;

signed main()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
    	a[i]=read();
    }
    sort(a+1,a+n+1);
	if(n%2==1)
	{
		for (int i=1;i<=n/2;i++) ans[++cnt]=a[i+n/2],ans[++cnt]=a[i];
		ans[++cnt]=a[n];
	}
	else for (int i=1;i<=n/2;i++) ans[++cnt]=a[i+n/2],ans[++cnt]=a[i];
	for (int i=2;i<=n-1;i++)
	  if (ans[i]<ans[i-1]&&ans[i]<ans[i+1]) Ans++;
	writeln(Ans);
	for (int i=1;i<=n;i++) writesp(ans[i]);
}