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

int T,n,k,ans,a[100005],cnt;

signed main()
{
	T=read();
	while (T--)
	{
		n=read(),k=read();ans=-1,k--;a[0]=-INT_MAX;cnt=0;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();
			if (a[i]!=a[i-1]) ans++;
		}
		for (int i=2;i<=n;i++)
		  cnt+=(a[i]^a[i-1]);
		if (cnt==0) 
		{
			writeln(1);
			continue;
		}
		if (k==0)
		{
			if (ans==0) writeln(1); else writeln(-1);
			continue;
		} else
		writeln((ans+k-1)/k);
	}
		
}