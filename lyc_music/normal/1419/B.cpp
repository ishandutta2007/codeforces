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

int T,m2[1000],f[1000],len,n,ans;

signed main()
{
	m2[0]=0;
	for (int i=1;i<100;i++)
	{
		m2[i]=m2[i-1]*2+1;
		f[i]=f[i-1]+(m2[i]*(m2[i]+1))/2;
		len=i;
		if (f[i]>1e18) break;
	}
    T=read();
    while (T--)
    {
    	n=read();
    	ans=upper_bound(f+1,f+len+1,n)-f-1;
		writeln(ans);
	}
}